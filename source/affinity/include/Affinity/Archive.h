// Copyright (c) 2020-2021 Vladimir Mamonov
// Licensed under the MIT license.

#ifndef AFFINITY_ARCHIVE_H
#define AFFINITY_ARCHIVE_H

#include "Affinity/Utils.h"

namespace AffinityReader {

class Driver
{
public:
	// You need to sub-class AffinityReader::Driver and provide you own implementation of these methods

	Driver()          = default;
	virtual ~Driver() = default;

	// Open file. Return false if file can't be opened. File name may be unused, it's all up to you how to implement the function.
	virtual bool Open([[maybe_unused]] const std::string& file_name) = 0;

	// Close file
	virtual void Close() = 0;

	// Read block. Return actual number of read bytes into bytes_read
	virtual void Read(void* data, size_t size, size_t* bytes_read) = 0;

	// Read block. ByteBuffer is std::vector<std::byte>
	virtual ByteBuffer Read(size_t size) = 0;

	// Sets the file's current position to the offset
	virtual bool Seek(uint64_t offset) = 0;

	// Checks the end of file
	virtual bool IsEOF() = 0;

	// Decompress Zip
	virtual ByteBuffer DecompressZip(const ByteBuffer& buf) = 0;

	// Decompress Zstd
	virtual ByteBuffer DecompressZstd(const ByteBuffer& buf) = 0;

	// Calc Crc-32
	virtual uint32_t Crc32(const ByteBuffer& buf) = 0;

	AF_NO_COPY(Driver);

protected:
};

class FileRevisionPrivate;

class FileRevision
{
public:
	enum class Type
	{
		Invalid = -1,
		Normal  = 1,
		Deleted = 2
	};

	FileRevision();
	virtual ~FileRevision();

	[[nodiscard]] uint64_t GetRevisionDate() const;
	[[nodiscard]] Type     GetType() const;
	[[nodiscard]] size_t   GetSize() const;
	[[nodiscard]] size_t   GetCompressedSize() const;

	friend class ArchivePrivate;

	AF_NO_COPY(FileRevision);

private:
	FileRevisionPrivate* m_pimpl;
};

class ArchivePrivate;

class Archive
{
public:
	explicit Archive(Driver* driver);
	virtual ~Archive();

	bool Load(const std::string& file_name);

	[[nodiscard]] bool DbgDump() const;

	[[nodiscard]] const std::vector<uint64_t>&    GetRevisionDates() const;
	[[nodiscard]] const std::vector<std::string>& GetFiles() const;

	[[nodiscard]] const std::string& GetErrorMessage() const;

	[[nodiscard]] const FileRevision* GetFileRevision(const std::string& name, uint64_t revision_date) const;
	[[nodiscard]] const FileRevision* GetHeadFileRevision(const std::string& name) const;

	bool Extract(const FileRevision* rev, ByteBuffer* out) const;

	AF_NO_COPY(Archive);

private:
	ArchivePrivate* m_pimpl;
};

} // namespace AffinityReader

#endif // AFFINITY_ARCHIVE_H
