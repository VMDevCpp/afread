// Copyright (c) 2020 Vladimir Mamonov
// Licensed under the MIT license.

#include "Affinity/Archive.h"

#include <algorithm>
#include <cinttypes>
#include <cstdio>
#include <cstring>
#include <memory>
#include <unordered_map>
#include <utility>

#define AF_ERROR(s)                                                                                                                        \
	{                                                                                                                                      \
		SetError(__FILE__, __LINE__, s);                                                                                                   \
		return false;                                                                                                                      \
	}

namespace AffinityReader {

class ArchivePrivate: public ErrorHandler
{
public:
	struct HeaderStruct
	{
		uint32_t file_tag;
		uint16_t version;
		uint16_t flag;
		uint32_t class_tag;
	};

	struct InfHeaderStruct
	{
		uint32_t tag;
		uint64_t fat_offset;
		uint64_t thmb_offset;
		uint64_t some_length;
		uint64_t unknown1;
		uint64_t creation_date;
		uint32_t revision;
		uint32_t some_num_2;
	};

	struct InfHeaderStruct2
	{
		uint32_t tag;
		uint32_t revision;
	};

	struct FatHeaderStruct
	{
		uint32_t tag;
		uint64_t next_offset;
		uint64_t creation_date;
		uint64_t some_offset;
		uint64_t some_length;
		uint64_t unknown5;
		uint32_t files_count;
		uint32_t unknown7;
		uint32_t unknown8;
		uint16_t dirs_count;
		uint8_t  unknown10;
	};

	struct FatFileStruct1
	{
		uint32_t id;
		uint8_t  flag;
	};

	struct FatFileStruct2
	{
		uint64_t offset;
		uint64_t size;
		uint64_t compressed_size;
		uint32_t crc32;
		uint8_t  compression;
		uint32_t unknown6;
		uint32_t unknown_fat4;
	};

	struct FatDirStruct
	{
		uint16_t str_len;
		uint16_t some_len;
		uint64_t files_num;
	};

	struct Fat
	{
		struct File
		{
			File() = default;

			virtual ~File() { delete rev; }

			[[nodiscard]] ByteBuffer Extract() const;

			FatFileStruct1 rec1 {};
			FatFileStruct2 rec2 {};
			std::string    name;
			Fat*           fat {nullptr};
			FileRevision*  rev {nullptr};

			AF_NO_COPY(File);
		};

		struct Dir
		{
			FatDirStruct h {};
			std::string  name;
		};

		Fat() = default;

		virtual ~Fat()
		{
			for (auto& p: files)
			{
				delete p;
			}
			for (auto& p: dirs)
			{
				delete p;
			}
		}

		FatHeaderStruct    h {};
		std::vector<File*> files;
		std::vector<Dir*>  dirs;
		ArchivePrivate*    archive {nullptr};
		uint64_t           compressed_size {0};

		AF_NO_COPY(Fat);
	};

	struct Header
	{
		Header() { Clear(); }

		void Clear()
		{
			memset(&h, 0, sizeof(HeaderStruct));
			memset(&inf, 0, sizeof(InfHeaderStruct));
			memset(&inf2, 0, sizeof(InfHeaderStruct2));
			thmb_present    = false;
			compressed_size = 0;
		}

		HeaderStruct     h {};
		InfHeaderStruct  inf {};
		InfHeaderStruct2 inf2 {};
		bool             thmb_present {false};
		uint64_t         compressed_size {0};
	};

	ArchivePrivate(Archive* a, Driver* d): archive(a), driver(d) {}

	~ArchivePrivate() override
	{
		for (auto& p: fats)
		{
			delete p;
		}
	}

	void Clear()
	{
		for (auto& p: fats)
		{
			delete p;
		}
		header.Clear();
		fats.clear();
		revisions.clear();
		ids.clear();
		files.clear();
	}

	ArchivePrivate(const ArchivePrivate&) = delete;
	ArchivePrivate& operator=(const ArchivePrivate&) = delete;
	ArchivePrivate(ArchivePrivate&&)                 = delete;
	ArchivePrivate& operator=(ArchivePrivate&&) = delete;

	void                DetectThumbnail();
	bool                Open(const std::string& file_name);
	bool                LoadHeader();
	bool                LoadFAT();
	bool                Extract(const FileRevision* rev, ByteBuffer* buf) const;
	const FileRevision* GetFileRevision(const std::string& name, uint64_t revision_date) const;
	bool                DbgDump();

	Archive*                                  archive;
	Driver*                                   driver;
	Header                                    header;
	std::vector<Fat*>                         fats;
	std::vector<uint64_t>                     revisions;
	std::unordered_map<std::string, uint32_t> ids;
	std::vector<std::string>                  files;

	static constexpr int TAG_FAT  = 0x54414623;
	static constexpr int TAG_FT2  = 0x32544623;
	static constexpr int TAG_FT3  = 0x33544623;
	static constexpr int TAG_FT4  = 0x34544623;
	static constexpr int TAG_FILE = 0x414bff00;
	static constexpr int TAG_INF  = 0x666e4923;
	static constexpr int TAG_PROT = 0x746f7250;
	static constexpr int TAG_THMB = 0x626d6854;
	static constexpr int TAG_FIL  = 0x6c694623;

	static constexpr int TAG_PRSN = 0x5072736e;
	static constexpr int TAG_PREF = 0x50726566;
	static constexpr int TAG_ADJM = 0x41646a6d;
	static constexpr int TAG_ASTP = 0x41737450;
	static constexpr int TAG_CROP = 0x43726f50;
	static constexpr int TAG_DEVP = 0x44657650;
	static constexpr int TAG_DCTS = 0x44637473;
	static constexpr int TAG_DOCP = 0x446f6350;
	static constexpr int TAG_EXPP = 0x45787050;
	static constexpr int TAG_FILS = 0x46696c73;
	static constexpr int TAG_GRDP = 0x47726450;
	static constexpr int TAG_MACS = 0x4d616373;
	static constexpr int TAG_OBJS = 0x4f626a73;
	static constexpr int TAG_OSTY = 0x4f537479;
	static constexpr int TAG_RBRU = 0x52427275;
	static constexpr int TAG_SHPS = 0x53687073;
	static constexpr int TAG_TONP = 0x546f6e50;
	static constexpr int TAG_TLST = 0x546c5374;
	static constexpr int TAG_VBRU = 0x56427275;

	static constexpr int TAG_ABDC = 0x41624463;
	static constexpr int TAG_AUCR = 0x41754372;
	static constexpr int TAG_FLTX = 0x466C5478;
	static constexpr int TAG_TBFM = 0x5462466d;
	static constexpr int TAG_TLEX = 0x546c4578;
	static constexpr int TAG_PRFP = 0x50726650;
};

class FileRevisionPrivate
{
public:
	ArchivePrivate::Fat::File* file;
};

#define AF_LOAD(var) /*NOLINT(cppcoreguidelines-macro-usage)*/                                                                             \
	{                                                                                                                                      \
		size_t bytes_read = 0;                                                                                                             \
		driver->Read(&(var), sizeof(var), &bytes_read);                                                                                    \
		if (bytes_read != sizeof(var))                                                                                                     \
		{                                                                                                                                  \
			AF_ERROR("can't read " + std::to_string(sizeof(var)) + " bytes");                                                              \
		}                                                                                                                                  \
	}

void ArchivePrivate::DetectThumbnail()
{
	size_t bytes_read   = 0;
	header.thmb_present = false;
	driver->Seek(header.inf.thmb_offset);
	if (!driver->IsEOF())
	{
		uint32_t thmb_1 = 0;
		uint32_t thmb_2 = 0;
		driver->Read(&thmb_1, 4, &bytes_read);
		if (bytes_read == 4)
		{
			driver->Read(&thmb_2, 4, &bytes_read);
			if (bytes_read == 4 && thmb_1 == 0xffffffff && thmb_2 == TAG_THMB)
			{
				header.thmb_present = true;
			}
		}
	}
}

void do_predict(uint8_t* dst)
{
	uint8_t  temp[0x10000];
	uint32_t size  = 0x4000;
	uint8_t* ptemp = temp;
	uint8_t* pdst  = dst;
	do
	{
		ptemp[0]      = pdst[1];
		ptemp[1]      = pdst[3];
		ptemp[0x8000] = pdst[0];
		ptemp[0x8001] = pdst[2];
		ptemp         = ptemp + 2;
		pdst          = pdst + 4;
		size--;
	} while (size != 0);
	memcpy(dst, temp, 0x10000);
}

void do_predict2(uint8_t* dst)
{
	uint8_t  temp[0x10000];
	uint32_t size  = 0x4000;
	uint8_t* ptemp = temp;
	uint8_t* pdst  = dst;
	do
	{
		ptemp[0]      = pdst[3];
		ptemp[0x4000] = pdst[2];
		ptemp[0x8000] = pdst[1];
		ptemp[0xc000] = pdst[0];
		ptemp         = ptemp + 1;
		pdst          = pdst + 4;
		size--;
	} while (size != 0);
	memcpy(dst, temp, 0x10000);
}

void undo_predict2(uint8_t* dst)
{
	uint8_t  temp[0x10000];
	uint32_t size  = 0x4000;
	uint8_t* ptemp = temp;
	uint8_t* pdst  = dst;
	do
	{
		ptemp[3] = pdst[0];
		ptemp[2] = pdst[0x4000];
		ptemp[1] = pdst[0x8000];
		ptemp[0] = pdst[0xc000];
		ptemp    = ptemp + 4;
		pdst     = pdst + 1;
		size--;
	} while (size != 0);
	memcpy(dst, temp, 0x10000);
}

void undo_predict(uint8_t* dst)
{
	uint8_t  temp[0x10000];
	uint32_t size  = 0x4000;
	uint8_t* ptemp = temp;
	uint8_t* pdst  = dst;
	do
	{
		ptemp[1] = pdst[0];
		ptemp[3] = pdst[1];
		ptemp[0] = pdst[0x8000];
		ptemp[2] = pdst[0x8001];
		ptemp    = ptemp + 4;
		pdst     = pdst + 2;
		size--;
	} while (size != 0);
	memcpy(dst, temp, 0x10000);
}

void undo_predict3(uint8_t* dst, size_t size)
{
	uint32_t byte = 0x00;
	for (size_t i = 0; i < size; i++)
	{
		byte   = (byte + dst[i]) & 0xffU;
		dst[i] = static_cast<uint8_t>(byte);
	}
}

void undo_predict4(uint16_t* dst, size_t size)
{
	uint32_t byte = 0x00;
	for (size_t i = 0; i < size; i++)
	{
		byte   = (byte + dst[i]) & 0xffffU;
		dst[i] = static_cast<uint16_t>(byte);
	}
}

const FileRevision* ArchivePrivate::GetFileRevision(const std::string& name, uint64_t revision_date) const
{
	auto elem = ids.find(name);

	if (elem == ids.end())
	{
		return nullptr;
	}

	auto id = elem->second;

	Fat::File* head_file     = nullptr;
	uint64_t   head_revision = 0;

	for (const auto& fat: fats)
	{
		for (auto& file: fat->files)
		{
			if (file->rec1.id == id && fat->h.creation_date > head_revision && fat->h.creation_date <= revision_date)
			{
				head_revision = fat->h.creation_date;
				head_file     = file;
			}
		}
	}

	return head_file != nullptr ? head_file->rev : nullptr;
}

bool ArchivePrivate::Extract(const FileRevision* rev, ByteBuffer* buf) const
{
	if (rev == nullptr)
	{
		AF_ERROR("no revision");
	}

	const auto& file = *rev->m_pimpl->file;

	if (file.rec2.size == 0)
	{
		AF_ERROR("empty file");
	}

	if (file.rec2.offset == 0)
	{
		AF_ERROR("invalid offset");
	}

	driver->Seek(file.rec2.offset);

	uint32_t tag = 0;
	AF_LOAD(tag);

	if (tag != TAG_FIL)
	{
		AF_ERROR("invalid tag");
	}

	auto flag = uint8_t(file.rec2.compression >> 5U) & 1U;
	auto alg  = (file.rec2.compression) & 3U;

	auto type = (file.rec2.compression) & 0xc0U;
	switch (type)
	{
		case 0x40:
			type = 1;
			flag = 0;
			break;
		case 0x80: type = 2; break;
		case 0xc0: type = 3; break;
		default: type = 0; flag = 0;
	}

	if (alg == 1)
	{
		*buf = driver->DecompressZip(driver->Read(file.rec2.compressed_size));
	} else if (alg == 2)
	{
		*buf = driver->DecompressZstd(driver->Read(file.rec2.compressed_size));
	} else
	{
		*buf = driver->Read(file.rec2.size);
	}

	if (buf->size() != file.rec2.size)
	{
		AF_ERROR("invalid size");
	}

	if (flag == 0)
	{
		if (type == 1)
		{
			undo_predict3(reinterpret_cast<uint8_t*>(buf->data()), buf->size());
		}
		if (type == 2)
		{
			undo_predict4(reinterpret_cast<uint16_t*>(buf->data()), buf->size() / 2);
		}
	}

	if (flag == 1)
	{
		if (type == 2)
		{
			undo_predict3(reinterpret_cast<uint8_t*>(buf->data()), buf->size());
			if (file.rec2.size == 0x10000)
			{
				undo_predict(reinterpret_cast<uint8_t*>(buf->data()));
			}
		}
	}

	uint32_t crc = driver->Crc32(*buf);

	if (crc != file.rec2.crc32)
	{
		AF_ERROR("invalid hash");
	}

	return true;
}

bool ArchivePrivate::Open(const std::string& file_name)
{
	if (!driver->Open(file_name))
	{
		AF_ERROR("can't open file");
	}

	return true;
}

bool ArchivePrivate::LoadHeader()
{
	driver->Seek(0);

	std::vector<int> supported_tags = {TAG_PRSN, TAG_PREF, TAG_ADJM, TAG_ASTP, TAG_CROP, TAG_DEVP, TAG_DCTS, TAG_DOCP, TAG_EXPP,
	                                   TAG_FILS, TAG_GRDP, TAG_MACS, TAG_OBJS, TAG_OSTY, TAG_RBRU, TAG_SHPS, TAG_TONP, TAG_TLST,
	                                   TAG_VBRU, TAG_ABDC, TAG_AUCR, TAG_FLTX, TAG_TBFM, TAG_TLEX, TAG_PRFP};

	AF_LOAD(header.h.file_tag);
	AF_LOAD(header.h.version);
	AF_LOAD(header.h.flag);
	AF_LOAD(header.h.class_tag);

	if (header.h.file_tag != TAG_FILE)
	{
		AF_ERROR("invalid tag");
	}

	if (header.h.version < 7 || header.h.version > 11)
	{
		AF_ERROR("invalid version");
	}

	if (std::find(supported_tags.begin(), supported_tags.end(), header.h.class_tag) == supported_tags.end())
	{
		AF_ERROR("unknown file");
	}

	AF_LOAD(header.inf.tag);
	AF_LOAD(header.inf.fat_offset);
	AF_LOAD(header.inf.thmb_offset);
	AF_LOAD(header.inf.some_length);
	AF_LOAD(header.inf.unknown1);
	AF_LOAD(header.inf.creation_date);
	AF_LOAD(header.inf.revision);
	AF_LOAD(header.inf.some_num_2);

	if (header.inf.tag != TAG_INF)
	{
		AF_ERROR("invalid tag");
	}

	if (header.h.version > 7)
	{
		AF_LOAD(header.inf2.tag);
		AF_LOAD(header.inf2.revision);

		if (header.inf2.tag != TAG_PROT)
		{
			AF_ERROR("invalid tag\n");
		}
	}

	if ((header.h.flag & 1U) == 0)
	{
		if ((header.h.flag & 2U) == 0)
		{
			if (!LoadFAT())
			{
				return false;
			}

			DetectThumbnail();
		} else
		{
			AF_ERROR("unknown format");
		}
	} else
	{
		AF_ERROR("unknown format");
	}

	return true;
}

bool ArchivePrivate::LoadFAT()
{
	Fat* pfat = nullptr;
	for (uint64_t offset = header.inf.fat_offset; offset != 0; offset = pfat->h.next_offset)
	{
		driver->Seek(offset);

		pfat      = new Fat;
		auto& fat = *pfat;

		fat.archive = this;

		AF_LOAD(fat.h.tag);
		AF_LOAD(fat.h.next_offset);
		AF_LOAD(fat.h.creation_date);
		AF_LOAD(fat.h.some_offset);
		AF_LOAD(fat.h.some_length);
		AF_LOAD(fat.h.unknown5);
		AF_LOAD(fat.h.files_count);
		AF_LOAD(fat.h.unknown7);
		AF_LOAD(fat.h.unknown8);
		AF_LOAD(fat.h.dirs_count);
		AF_LOAD(fat.h.unknown10);

		if (((fat.h.tag != TAG_FAT)) && (fat.h.tag != TAG_FT2) && (fat.h.tag != TAG_FT3) && (fat.h.tag != TAG_FT4))
		{
			AF_ERROR("Invalid FAT\n");
		}

		for (uint32_t i = 0; i < fat.h.files_count; i++)
		{
			auto*      pfile = new Fat::File;
			Fat::File& file  = *pfile;

			file.fat = pfat;

			AF_LOAD(file.rec1.id);
			AF_LOAD(file.rec1.flag);

			if (file.rec1.flag != 0 && file.rec1.flag != 1 && file.rec1.flag != 2)
			{
				AF_ERROR("invalid flag");
			}

			if (file.rec1.flag == 0 || file.rec1.flag == 1)
			{
				AF_LOAD(file.rec2.offset);
				AF_LOAD(file.rec2.size);
				AF_LOAD(file.rec2.compressed_size);
				AF_LOAD(file.rec2.crc32);
				AF_LOAD(file.rec2.compression);

				if (fat.h.tag == TAG_FAT)
				{
					file.rec2.unknown6 = 0;
				} else
				{
					AF_LOAD(file.rec2.unknown6);
				}

				if (fat.h.tag != TAG_FT4)
				{
					file.rec2.unknown_fat4 = 0;
				} else
				{
					AF_LOAD(file.rec2.unknown_fat4);
				}

				if (fat.h.tag == TAG_FAT || fat.h.tag == TAG_FT2)
				{
					switch (file.rec2.compression)
					{
						case 0x01: file.rec2.compression = 0x01; break;
						case 0x02: file.rec2.compression = 0x41; break;
						case 0x03: file.rec2.compression = 0x81; break;
						case 0x04: file.rec2.compression = 0xc1; break;
						default: file.rec2.compression = 0; break;
					}
				}
			}

			if (file.rec1.flag == 0)
			{
				uint16_t str_len = 0;
				AF_LOAD(str_len);
				auto buf  = driver->Read(str_len);
				file.name = std::string(reinterpret_cast<const char*>(buf.data()), str_len);

				auto elem = ids.find(file.name);
				if (elem == ids.end())
				{
					ids[file.name] = file.rec1.id;
					files.push_back(file.name);
				} else
				{
					if (elem->second != file.rec1.id)
					{
						AF_ERROR("invalid id");
					}
				}
			}

			fat.compressed_size += file.rec2.compressed_size;
			fat.files.push_back(pfile);

			auto* rev          = new FileRevision();
			rev->m_pimpl->file = pfile;
			file.rev           = rev;
		}

		for (uint32_t i = 0; i < fat.h.dirs_count; i++)
		{
			auto*     pdir = new Fat::Dir;
			Fat::Dir& dir  = *pdir;

			AF_LOAD(dir.h.str_len);
			AF_LOAD(dir.h.some_len);
			AF_LOAD(dir.h.files_num);

			auto buf = driver->Read(dir.h.str_len);
			dir.name = std::string(reinterpret_cast<const char*>(buf.data()), dir.h.str_len);

			if (dir.h.some_len != 0)
			{
				AF_ERROR("unknown format");
			}

			fat.dirs.push_back(pdir);
		}

		header.compressed_size += pfat->compressed_size;
		fats.push_back(pfat);

		revisions.push_back(fat.h.creation_date);
	}

	std::sort(revisions.begin(), revisions.end());

	return true;
}

bool ArchivePrivate::DbgDump()
{
	int width = 0;
	printf("files (%d): ", static_cast<int>(files.size()));
	for (int i = 0; i < static_cast<int>(files.size()); i++)
	{
		printf("%s%s%s", i == 0 ? "" : ", ", files.at(i).c_str(), i == static_cast<int>(files.size()) - 1 ? "\n" : "");
		if (static_cast<int>(files.at(i).size()) > width)
		{
			width = static_cast<int>(files.at(i).size());
		}
	}

	printf("revisions (%d): ", static_cast<int>(revisions.size()));
	for (int i = 0; i < static_cast<int>(revisions.size()); i++)
	{
		printf("%s0x%" PRIx64 "%s", i == 0 ? "" : ", ", revisions.at(i), i == static_cast<int>(revisions.size()) - 1 ? "\n" : "");
	}

	for (const auto& name: files)
	{
		printf("%-*s:", width, name.c_str());

		for (auto date: revisions)
		{
			const auto* file = GetFileRevision(name, date);
			if (file != nullptr)
			{
				printf(" -> 0x%" PRIx64 "(%d)", file->GetRevisionDate(), static_cast<int>(file->GetType()));
			} else
			{
				printf(" -> (null)       ");
			}
		}
		printf("\n");
	}

	printf("header.h.file_tag        = 0x%" PRIx32 "\n", header.h.file_tag);
	printf("header.h.version         = 0x%" PRIx16 "\n", header.h.version);
	printf("header.h.flag            = 0x%" PRIx16 "\n", header.h.flag);
	printf("header.h.class_tag       = 0x%" PRIx32 "\n", header.h.class_tag);
	printf("header.inf.fat_offset    = 0x%" PRIx64 "\n", header.inf.fat_offset);
	printf("header.inf.thmb_offset   = 0x%" PRIx64 "\n", header.inf.thmb_offset);
	printf("header.inf.some_length   = 0x%" PRIx64 "\n", header.inf.some_length);
	printf("header.inf.unknown1      = 0x%" PRIx64 "\n", header.inf.unknown1);
	printf("header.inf.creation_date = 0x%" PRIx64 "\n", header.inf.creation_date);
	printf("header.inf.revision      = %" PRIu32 "\n", header.inf.revision);
	printf("header.inf.some_num_2    = 0x%" PRIx32 "\n", header.inf.some_num_2);
	printf("header.inf2.tag          = 0x%" PRIx32 "\n", header.inf2.tag);
	printf("header.inf2.revision     = %" PRIu32 "\n", header.inf2.revision);
	printf("header.thmb_present      = %s\n", header.thmb_present ? "true" : "false");
	printf("header.compressed_size   = 0x%" PRIx64 "\n", header.compressed_size);

	int fats_num = static_cast<int>(fats.size());
	printf("header.fats_num = %d\n", fats_num);
	for (int fat_index = 0; fat_index < fats_num; fat_index++)
	{
		const auto& fat = *fats.at(fat_index);

		printf("  fats[%d].h.tag           = 0x%" PRIx32 "\n", fat_index, fat.h.tag);
		printf("  fats[%d].h.next_offset   = 0x%" PRIx64 "\n", fat_index, fat.h.next_offset);
		printf("  fats[%d].h.creation_date = 0x%" PRIx64 "\n", fat_index, fat.h.creation_date);
		printf("  fats[%d].h.some_offset   = 0x%" PRIx64 "\n", fat_index, fat.h.some_offset);
		printf("  fats[%d].h.some_length   = 0x%" PRIx64 "\n", fat_index, fat.h.some_length);
		printf("  fats[%d].h.unknown5      = 0x%" PRIx64 "\n", fat_index, fat.h.unknown5);
		printf("  fats[%d].h.files_count   = %" PRIu32 "\n", fat_index, fat.h.files_count);
		printf("  fats[%d].h.unknown7      = 0x%" PRIx32 "\n", fat_index, fat.h.unknown7);
		printf("  fats[%d].h.unknown8      = 0x%" PRIx32 "\n", fat_index, fat.h.unknown8);
		printf("  fats[%d].h.dirs_count    = %" PRIu16 "\n", fat_index, fat.h.dirs_count);
		printf("  fats[%d].h.unknown10     = 0x%" PRIx8 "\n", fat_index, fat.h.unknown10);
		printf("  fats[%d].compressed_size = 0x%" PRIx64 "\n", fat_index, fat.compressed_size);

		int files_num = static_cast<int>(fat.files.size());
		for (int files_index = 0; files_index < files_num; files_index++)
		{
			const auto& file = *fat.files.at(files_index);

			printf("    file[%d].rec1.id              = %" PRIu32 "\n", files_index, file.rec1.id);
			printf("    file[%d].rec1.flag            = %" PRIu8 "\n", files_index, file.rec1.flag);
			printf("    file[%d].rec2.offset          = 0x%" PRIx64 "\n", files_index, file.rec2.offset);
			printf("    file[%d].rec2.size            = 0x%" PRIx64 "\n", files_index, file.rec2.size);
			printf("    file[%d].rec2.compressed_size = 0x%" PRIx64 "\n", files_index, file.rec2.compressed_size);
			printf("    file[%d].rec2.crc32           = 0x%" PRIx32 "\n", files_index, file.rec2.crc32);
			printf("    file[%d].rec2.compression     = 0x%" PRIx8 "\n", files_index, file.rec2.compression);
			printf("    file[%d].rec2.unknown6        = 0x%" PRIx32 "\n", files_index, file.rec2.unknown6);
			printf("    file[%d].rec2.unknown_fat4    = 0x%" PRIx32 "\n", files_index, file.rec2.unknown_fat4);
			printf("    file[%d].name                 = \"%s\"\n", files_index, file.name.c_str());

			if (file.rec2.size > 0)
			{
				ByteBuffer buf;
				if (!Extract(file.rev, &buf))
				{
					return false;
				}
			}
		}

		int dirs_num = static_cast<int>(fat.dirs.size());
		for (int dirs_index = 0; dirs_index < dirs_num; dirs_index++)
		{
			const auto& dir = *fat.dirs.at(dirs_index);

			printf("    dir[%d].str_len   = %d\n", dirs_index, static_cast<int>(dir.h.str_len));
			printf("    dir[%d].some_len  = %d\n", dirs_index, static_cast<int>(dir.h.some_len));
			printf("    dir[%d].files_num = %" PRIu64 "\n", dirs_index, dir.h.files_num);
			printf("    dir[%d].name      = \"%s\"\n", dirs_index, dir.name.c_str());
		}
	}

	return true;
}

Archive::Archive(Driver* driver): m_pimpl(new ArchivePrivate(this, driver)) {}

Archive::~Archive()
{
	m_pimpl->driver->Close();
	delete m_pimpl;
}

bool Archive::Load(const std::string& file_name)
{
	if (!m_pimpl->Open(file_name))
	{
		return false;
	}

	m_pimpl->Clear();

	return m_pimpl->LoadHeader();
}

const std::vector<uint64_t>& Archive::GetRevisionDates() const
{
	return m_pimpl->revisions;
}

const std::vector<std::string>& Archive::GetFiles() const
{
	return m_pimpl->files;
}

const std::string& Archive::GetErrorMessage() const
{
	return m_pimpl->GetErrorMessage();
}

bool Archive::DbgDump() const
{
	return m_pimpl->DbgDump();
}

FileRevision::FileRevision(): m_pimpl(new FileRevisionPrivate) {}

FileRevision::~FileRevision()
{
	delete m_pimpl;
}

const FileRevision* Archive::GetFileRevision(const std::string& name, uint64_t revision_date) const
{
	return m_pimpl->GetFileRevision(name, revision_date);
}

const FileRevision* Archive::GetHeadFileRevision(const std::string& name) const
{
	return m_pimpl->GetFileRevision(name, UINT64_MAX);
}

uint64_t FileRevision::GetRevisionDate() const
{
	return m_pimpl->file->fat->h.creation_date;
}

FileRevision::Type FileRevision::GetType() const
{
	auto flag = m_pimpl->file->rec1.flag;

	switch (flag)
	{
		case 0:
		case 1: return Type::Normal;
		case 2: return Type::Deleted;
		default: return Type::Invalid;
	}

	return Type::Invalid;
}

bool Archive::Extract(const FileRevision* rev, ByteBuffer* out) const
{
	return m_pimpl->Extract(rev, out);
}

size_t FileRevision::GetSize() const
{
	return m_pimpl->file->rec2.size;
}

size_t FileRevision::GetCompressedSize() const
{
	return m_pimpl->file->rec2.compressed_size;
}

} // namespace AffinityReader
