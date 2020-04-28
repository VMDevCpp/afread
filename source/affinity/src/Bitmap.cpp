// Copyright (c) 2020 Vladimir Mamonov
// Licensed under the MIT license.

#include "Affinity/Bitmap.h"

#include "Affinity/Archive.h"
#include "Affinity/CppStructs.h"
#include "Affinity/Model.h"

#include <cstdio>
#include <cstring>
#include <initializer_list>

namespace AffinityReader {

static void block_clear(uint8_t* ptr, uint32_t clear_value, int pitch, int width, int height)
{
	uint8_t* ptr_end = ptr + pitch * height;
	for (; ptr < ptr_end; ptr += pitch)
	{
		auto* p_end = reinterpret_cast<uint32_t*>(ptr + width);
		for (auto* p = reinterpret_cast<uint32_t*>(ptr); p < p_end; p++)
		{
			*p = clear_value;
		}
	}
}

static void block_copy(uint8_t* dst, const uint8_t* src, int dst_pitch, int src_pitch, int width, int height)
{
	uint8_t*       dst_end = dst + dst_pitch * height;
	const uint8_t* src_end = src + src_pitch * height;
	for (; dst < dst_end && src < src_end; dst += dst_pitch, src += src_pitch)
	{
		std::memcpy(dst, src, width);
	}
}

static bool channel_load(uint8_t* pixels, const std::vector<CppModel::Blck*>& idx, const std::vector<uint8_t>& sta,
                         const AffinityReader::Archive* archive, int pitch, int max_x, int max_y)
{
	int x = 0;
	int y = 0;

	auto block      = idx.begin();
	auto last_block = idx.end();

	AffinityReader::ByteBuffer buf;

	for (auto block_type: sta)
	{
		switch (block_type)
		{
			case 0:
			case 1: block_clear(&pixels[y * pitch + x], 0, pitch, 256, 256); break;
			case 2: block_clear(&pixels[y * pitch + x], 0xFFFFFFFFu, pitch, 256, 256); break;
			case 3: block_clear(&pixels[y * pitch + x], 0x3F800000u, pitch, 256, 256); break;
			case 4:
			{
				if (block == last_block)
				{
					// printf("no more blocks\n");
					return false;
				}

				int32_t rect[4] {};
				std::memcpy(rect, (*block)->Rect, sizeof(rect));

				// TODO(): cache blocks by name
				if (const auto* rev = archive->GetHeadFileRevision((*block)->Data.data); rev == nullptr || !archive->Extract(rev, &buf))
				{
					// printf("can't extract block\n");
					return false;
				}

				if (buf.size() != 65536)
				{
					// printf("wrong size\n");
					return false;
				}

				block++;

				block_clear(&pixels[y * pitch + x], 0, pitch, 256, 256);
				block_copy(&pixels[(y + rect[1]) * pitch + x + rect[0]], reinterpret_cast<uint8_t*>(&buf[rect[1] * 256 + rect[0]]), pitch,
				           256, rect[2] - rect[0], rect[3] - rect[1]);
				break;
			}
			default: // printf("unknown block: %d\n", static_cast<int>(block_type));
				return false;
		}

		x += 256;
		if (x >= max_x)
		{
			x = 0;
			y += 256;

			if (y >= max_y)
			{
				break;
			}
		}
	}
	return true;
}

Bitmap::Bitmap(const CppModel::Rstr* layer, const Archive* archive)
{
	// CppModel::BaseBitm::Type::EmbR (external image) is not supported
	if (layer->Bitm != nullptr && layer->Bitm->base_type == CppModel::BaseBitm::Type::DyBm)
	{
		auto* bm = static_cast<CppModel::DyBm*>(layer->Bitm);

		switch (bm->Frmt.Id())
		{
			case 0:
				m_pixel_size   = 1;
				m_channels_num = 4;
				m_format       = BitmapFormat::RGB8;
				break;
			case 1:
				m_pixel_size   = 2;
				m_channels_num = 4;
				m_format       = BitmapFormat::RGB16;
				break;
			case 2:
				m_pixel_size   = 1;
				m_channels_num = 2;
				m_format       = BitmapFormat::Gray8;
				break;
			case 3:
				m_pixel_size   = 2;
				m_channels_num = 2;
				m_format       = BitmapFormat::Gray16;
				break;
			case 4:
				m_pixel_size   = 1;
				m_channels_num = 5;
				m_format       = BitmapFormat::CMYK8;
				break;
			case 5:
				m_pixel_size   = 2;
				m_channels_num = 4;
				m_format       = BitmapFormat::LAB16;
				break;
			case 9:
				m_pixel_size   = 4;
				m_channels_num = 4;
				m_format       = BitmapFormat::RGB32;
				break;
			default: printf("unknown format: %d.%d\n", bm->Frmt.version, bm->Frmt.id); return;
		}

		m_width  = bm->BmpW;
		m_height = bm->BmpH;
		int bx   = ((m_width * m_pixel_size - 1) / 256) + 1;
		int by   = ((m_height - 1) / 256) + 1;
		m_pitch  = bx * 256;
		m_pixels = new uint8_t*[m_channels_num];

		// printf("m_width = %d, m_height = %d, bx = %d, by = %d, m_pitch = %d, m_pixel_size = %d, m_channels_num = %d\n", m_width,
		// m_height, bx, by, m_pitch, m_pixel_size, m_channels_num);

		for (int i = 0; i < m_channels_num; i++)
		{
			m_pixels[i] = new uint8_t[m_pitch * by * 256];
		}

		bool ok = true;
		switch (m_channels_num)
		{
			case 5:
				ok = ok && channel_load(m_pixels[4], bm->Idx5, bm->Sta5, archive, m_pitch, m_width * m_pixel_size, m_height);
				[[fallthrough]];
			case 4:
				ok = ok && channel_load(m_pixels[3], bm->Idx4, bm->Sta4, archive, m_pitch, m_width * m_pixel_size, m_height);
				ok = ok && channel_load(m_pixels[2], bm->Idx3, bm->Sta3, archive, m_pitch, m_width * m_pixel_size, m_height);
				[[fallthrough]];
			case 2:
				ok = ok && channel_load(m_pixels[1], bm->Idx2, bm->Sta2, archive, m_pitch, m_width * m_pixel_size, m_height);
				ok = ok && channel_load(m_pixels[0], bm->Idx1, bm->Sta1, archive, m_pitch, m_width * m_pixel_size, m_height);
				break;
			default:
				ok = false;
				// printf("unknown channels num: %d\n", m_channels_num);
				break;
		}

		if (!ok)
		{
			m_format = BitmapFormat::Unknown;
		}
	}
}

Bitmap::~Bitmap()
{
	for (int i = 0; i < m_channels_num; i++)
	{
		delete[] m_pixels[i];
	}
	delete[] m_pixels;
}

void Bitmap::GetPixelCmyk(int px, int py, float* c, float* m, float* y, float* k, float* alpha) const
{
	int offset = py * m_pitch + px * m_pixel_size;
	switch (m_format)
	{
		case BitmapFormat::CMYK8:
			*c     = static_cast<float>(*reinterpret_cast<uint8_t*>(m_pixels[0] + offset)) / 255.0f;
			*m     = static_cast<float>(*reinterpret_cast<uint8_t*>(m_pixels[1] + offset)) / 255.0f;
			*y     = static_cast<float>(*reinterpret_cast<uint8_t*>(m_pixels[2] + offset)) / 255.0f;
			*k     = static_cast<float>(*reinterpret_cast<uint8_t*>(m_pixels[3] + offset)) / 255.0f;
			*alpha = static_cast<float>(*reinterpret_cast<uint8_t*>(m_pixels[4] + offset)) / 255.0f;
			break;
		default: *c = *m = *y = *k = *alpha = 0.0f; break;
	}
}

void Bitmap::GetPixelGray(int px, int py, float* gray, float* alpha) const
{
	int offset = py * m_pitch + px * m_pixel_size;
	switch (m_format)
	{
		case BitmapFormat::Gray8:
			*gray  = static_cast<float>(*reinterpret_cast<uint8_t*>(m_pixels[0] + offset)) / 255.0f;
			*alpha = static_cast<float>(*reinterpret_cast<uint8_t*>(m_pixels[1] + offset)) / 255.0f;
			break;
		case BitmapFormat::Gray16:
			*gray  = static_cast<float>(*reinterpret_cast<uint16_t*>(m_pixels[0] + offset)) / 65535.0f;
			*alpha = static_cast<float>(*reinterpret_cast<uint16_t*>(m_pixels[1] + offset)) / 65535.0f;
			break;
		default: *gray = *alpha = 0.0f; break;
	}
}

void Bitmap::GetPixelRgb(int px, int py, float* r, float* g, float* b, float* alpha) const
{
	float f[4] {};
	int   offset = py * m_pitch + px * m_pixel_size;
	switch (m_format)
	{
		case BitmapFormat::RGB8:
			for (int i: {0, 1, 2, 3})
			{
				f[i] = static_cast<float>(*reinterpret_cast<uint8_t*>(m_pixels[i] + offset)) / 255.0f;
			}
			break;
		case BitmapFormat::RGB16:
			for (int i: {0, 1, 2, 3})
			{
				f[i] = static_cast<float>(*reinterpret_cast<uint16_t*>(m_pixels[i] + offset)) / 65535.0f;
			}
			break;
		case BitmapFormat::RGB32:
			for (int i: {0, 1, 2, 3})
			{
				f[i] = *reinterpret_cast<float*>(m_pixels[i] + offset);
			}
			break;
		default: break;
	}
	*r     = f[0];
	*g     = f[1];
	*b     = f[2];
	*alpha = f[3];
}

void Bitmap::GetPixelLab(int px, int py, float* l, float* a, float* b, float* alpha) const
{
	int offset = py * m_pitch + px * m_pixel_size;
	switch (m_format)
	{
		case BitmapFormat::LAB16:
			*l     = 100.0f * (static_cast<float>(*reinterpret_cast<uint16_t*>(m_pixels[0] + offset)) / 65535.0f);
			*a     = 255.0f * (static_cast<float>(*reinterpret_cast<uint16_t*>(m_pixels[1] + offset)) / 65535.0f) - 128.0f;
			*b     = 255.0f * (static_cast<float>(*reinterpret_cast<uint16_t*>(m_pixels[2] + offset)) / 65535.0f) - 128.0f;
			*alpha = static_cast<float>(*reinterpret_cast<uint16_t*>(m_pixels[3] + offset)) / 65535.0f;
			break;
		default: *l = *a = *b = *alpha = 0.0f; break;
	}
}

} // namespace AffinityReader
