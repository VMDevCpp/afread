#include "Compression.h"

#include "zstd.h"

#include <cstdint>

#define MINIZ_NO_STDIO
#define MINIZ_NO_MALLOC
//#define MZ_ASSERT(x) assert(x)
#if __clang__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-value"
#include "miniz.c.h"
#pragma GCC diagnostic pop
#else
#include "miniz.c.h"
#endif

#define AF_ZIP_OUT_BUF_SIZE (16 * 1024)

namespace afread {

namespace ZipImpl {
void* Alloc(void* /*opaque*/, size_t items, size_t size)
{
	return new char[items * size];
}

void Free(void* /*opaque*/, void* address)
{
	delete[] static_cast<char*>(address);
}

} // namespace ZipImpl

ByteBuffer DecompressZstd(void* buf, size_t length)
{
	ByteBuffer       r;
	size_t           buff_out_size = ZSTD_DStreamOutSize();
	Byte*            buff_out      = new Byte[buff_out_size];
	ZSTD_DCtx* const dctx          = ZSTD_createDCtx();
	ZSTD_inBuffer    input         = {buf, length, 0};
	while (input.pos < input.size)
	{
		ZSTD_outBuffer output = {buff_out, buff_out_size, 0};
		auto           ret    = ZSTD_decompressStream(dctx, &output, &input);
		if (ZSTD_isError(ret) != 0u)
		{
			break;
		}
		size_t size = r.size();
		r.resize(size + output.pos);
		memcpy(r.data() + size, buff_out, output.pos);
	}
	ZSTD_freeDCtx(dctx);
	delete[] buff_out;
	return r;
}

ByteBuffer DecompressZip(void* buf, size_t length)
{
	int       status;
	mz_stream stream;
	memset(&stream, 0, sizeof(stream));

	ByteBuffer out;
	uint8_t    temp_buf[AF_ZIP_OUT_BUF_SIZE];

	stream.next_in  = static_cast<unsigned char*>(buf);
	stream.avail_in = static_cast<unsigned int>(length);
	stream.zalloc   = ZipImpl::Alloc;
	stream.zfree    = ZipImpl::Free;

	status = mz_inflateInit(&stream);

	if (status == MZ_OK)
	{
		for (;;)
		{
			stream.next_out  = temp_buf;
			stream.avail_out = AF_ZIP_OUT_BUF_SIZE;

			status = mz_inflate(&stream, MZ_NO_FLUSH);

			if (status != MZ_OK && status != MZ_STREAM_END)
			{
				break;
			}

			size_t size = out.size();
			out.resize(size + AF_ZIP_OUT_BUF_SIZE - stream.avail_out);
			memcpy(out.data() + size, temp_buf, AF_ZIP_OUT_BUF_SIZE - stream.avail_out);

			if (status != MZ_OK)
			{
				break;
			}
		}

		mz_deflateEnd(&stream);
	}

	return out;
}

} // namespace afread
