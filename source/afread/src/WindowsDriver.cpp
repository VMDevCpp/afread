#include "WindowsDriver.h"

#include "Compression.h"

#include <windows.h>

namespace afread {

namespace CRC32 {

static uint32_t crc_table[256]  = {0};
static bool     crc_initialized = false;

uint32_t Hash(const uint8_t* buf, uint32_t length)
{
	uint32_t crc;

	if (!crc_initialized)
	{
		for (int i = 0; i < 256; i++)
		{
			crc = i;
			for (int j = 0; j < 8; j++)
			{
				crc = crc & 1 ? (crc >> 1) ^ 0xEDB88320 : crc >> 1;
			}
			crc_table[i] = crc;
		};

		crc_initialized = true;
	}

	crc = 0xFFFFFFFF;
	while (length--)
	{
		crc = crc_table[(crc ^ *buf++) & 0xFF] ^ (crc >> 8);
	}

	return crc ^ 0xFFFFFFFF;
}
} // namespace CRC32

static std::wstring str_to_wstr(const std::string& str)
{
	std::wstring ret;
	wchar_t*     temp = new wchar_t[str.length() + 1];
	temp[str.size()]  = 0;
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, temp, (int)str.length());
	ret = temp;
	delete[] temp;
	return ret;
}

WindowsDriver::WindowsDriver(): m_file(INVALID_HANDLE_VALUE) {}

bool WindowsDriver::Open(const std::string& file_name)
{
	m_file_name = file_name;
	m_file      = CreateFileW(str_to_wstr(m_file_name).c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
	if (m_file == INVALID_HANDLE_VALUE)
	{
		return false;
	}
	return true;
}

void WindowsDriver::Close()
{
	if (m_file != INVALID_HANDLE_VALUE)
	{
		CloseHandle(m_file);
	}
}

void WindowsDriver::Read(void* data, size_t size, size_t* bytes_read)
{
	DWORD w = 0;
	if (m_file != INVALID_HANDLE_VALUE)
	{
		ReadFile(m_file, data, (DWORD)size, &w, 0);
	}
	if (bytes_read) *bytes_read = w;
}

AffinityReader::ByteBuffer WindowsDriver::Read(size_t size)
{
	size_t                     bytes_read;
	AffinityReader::ByteBuffer ret(size);
	Read(ret.data(), size, &bytes_read);
	ret.resize(bytes_read);
	return ret;
}

bool WindowsDriver::Seek(uint64_t offset)
{
	bool ok = true;
	if (m_file != INVALID_HANDLE_VALUE)
	{
		LARGE_INTEGER s;
		s.QuadPart = offset;
		ok         = (SetFilePointerEx(m_file, s, 0, FILE_BEGIN) != 0);
	}
	return ok;
}

bool WindowsDriver::IsEOF()
{
	if (m_file != INVALID_HANDLE_VALUE)
	{
		LARGE_INTEGER sz, s, r;
		GetFileSizeEx(m_file, &sz);
		s.QuadPart = 0;
		SetFilePointerEx(m_file, s, &r, FILE_CURRENT);
		return r.QuadPart >= sz.QuadPart;
	}
	return true;
}

AffinityReader::ByteBuffer WindowsDriver::DecompressZip(const AffinityReader::ByteBuffer& buf)
{
	return afread::DecompressZip((void*)buf.data(), buf.size());
}

AffinityReader::ByteBuffer WindowsDriver::DecompressZstd(const AffinityReader::ByteBuffer& buf)
{
	return afread::DecompressZstd((void*)buf.data(), buf.size());
}

uint32_t WindowsDriver::Crc32(const AffinityReader::ByteBuffer& buf)
{
	return CRC32::Hash((const uint8_t*)buf.data(), (uint32_t)buf.size());
}

} // namespace afread
