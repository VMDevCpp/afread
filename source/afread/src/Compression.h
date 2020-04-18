#ifndef AFREAD_INCLUDE_COMPRESSION_H_
#define AFREAD_INCLUDE_COMPRESSION_H_

#include <vector>

namespace afread {

using ByteBuffer = std::vector<std::byte>;

ByteBuffer DecompressZstd(void* buf, size_t length);
ByteBuffer DecompressZip(void* buf, size_t length);

} // namespace afread

#endif /* AFREAD_INCLUDE_COMPRESSION_H_ */
