// Copyright (c) 2020-2021 Vladimir Mamonov
// Licensed under the MIT license.

#ifndef AFFINITY_UTILS_H
#define AFFINITY_UTILS_H

// IWYU pragma: begin_exports
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
// IWYU pragma: end_exports

#if __cplusplus < 201703L
#error "C++ 17 required"
#endif

#define AF_NO_COPY(name)                                                                                                                   \
	name(const name&) = delete;            /* NOLINT(bugprone-macro-parentheses)*/                                                         \
	name& operator=(const name&) = delete; /* NOLINT(bugprone-macro-parentheses)*/                                                         \
	name(name&&)                 = delete; /* NOLINT(bugprone-macro-parentheses)*/                                                         \
	name& operator=(name&&) = delete;      /* NOLINT(bugprone-macro-parentheses)*/

#define AF_DEFAULT_COPY(name)                                                                                                              \
	name(const name&) = default;            /* NOLINT(bugprone-macro-parentheses)*/                                                        \
	name& operator=(const name&) = default; /* NOLINT(bugprone-macro-parentheses)*/                                                        \
	name(name&&)                 = default; /* NOLINT(bugprone-macro-parentheses)*/                                                        \
	name& operator=(name&&) = default;      /* NOLINT(bugprone-macro-parentheses)*/

namespace AffinityReader {

using ByteBuffer = std::vector<std::byte>;

class ErrorHandler
{
public:
	ErrorHandler()          = default;
	virtual ~ErrorHandler() = default;

	void SetError(const std::string& file, int line, const std::string& msg) const
	{
		m_error_message = "Error: " + msg + " in " + file + ":" + std::to_string(line);
	}

	void ResetError() const { m_error_message.clear(); }

	const std::string& GetErrorMessage() const { return m_error_message; }

	void SetErrorMessage(const std::string& error_message) { m_error_message = error_message; }

	AF_NO_COPY(ErrorHandler);

private:
	mutable std::string m_error_message;
};

inline constexpr uint32_t operator"" _tag(const char* ss, const size_t /*size*/) noexcept
{
	return uint32_t((uint32_t(ss[0]) << 24U) | (uint32_t(ss[1]) << 16U) | (uint32_t(ss[2]) << 8U) | (uint32_t(ss[3])));
}

class Stream
{
public:
	Stream(const ByteBuffer::value_type* data, size_t pos, size_t size): m_data(data), m_pos(pos), m_size(size) {}

	bool Read(void* data, size_t size)
	{
		if (m_pos + size > m_size)
		{
			return false;
		}
		memcpy(data, m_data + m_pos, size);
		m_pos += size;
		return true;
	}

	bool Read(std::string* s, size_t size)
	{
		if (m_pos + size > m_size)
		{
			return false;
		}
		*s = std::string(reinterpret_cast<const char*>(m_data + m_pos), size);
		m_pos += size;
		return true;
	}

	[[nodiscard]] size_t GetPos() const { return m_pos; }

private:
	const ByteBuffer::value_type* m_data;
	size_t                        m_pos;
	size_t                        m_size;
};

inline std::string BufferToString(const ByteBuffer& buf)
{
	std::stringstream str;
	for (auto b: buf)
	{
		str << std::setfill('0') << std::setw(2) << std::hex << int(b);
	}
	return str.str();
}

inline std::string QuotedString(const std::string& str)
{
	std::stringstream s;
	for (uint8_t p: str)
	{
		if (p == '"' || p == '\\')
		{
			s << '\\' << p;
		} else if (p >= 0x20)
		{
			s << p;
		} else
		{
			s << "\\u" << std::setfill('0') << std::setw(4) << std::hex << static_cast<int>(p) << std::dec;
		}
	}
	return '"' + s.str() + '"';
}

inline std::string TagToString(uint32_t tag)
{
	std::stringstream s;
	const char*       p = reinterpret_cast<const char*>(&tag);
	s << p[3] << p[2] << p[1] << p[0];
	return QuotedString(s.str());
}

} // namespace AffinityReader

#endif // AFFINITY_UTILS_H
