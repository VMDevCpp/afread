// Copyright (c) 2020 Vladimir Mamonov
// Licensed under the MIT license.

#include "Affinity/Affinity.h"

#include "Affinity/Archive.h"
#include "Affinity/Cpp.h"
#include "Affinity/Reader.h"

#include <cctype>

namespace AffinityReader {

class AffinityPrivate
{
public:
	void                      Clear();
	bool                      Load(const std::string& file_name, Driver* driver);
	[[nodiscard]] std::string GetErrMsg() const;

	Affinity::Type                  type = {Affinity::Type::Unknown};
	AffinityReader::CppModel::PCFl* pcfl = {nullptr};
	AffinityReader::CppModel::Pers* pers = {nullptr};
	AffinityReader::CppModel::Pref* pref = {nullptr};

	AffinityReader::Archive* archive = {nullptr};
	AffinityReader::Reader*  reader  = {nullptr};
	AffinityReader::Cpp*     cpp     = {nullptr};

	std::string error_msg;
};

static bool EndsWith(const std::string& str, const std::string& suffix)
{
	if (suffix.length() > str.length())
	{
		return false;
	}
	size_t d = str.length() - suffix.length();
	for (size_t i = 0; i < suffix.length(); i++)
	{
		if (std::tolower(suffix[i]) != std::tolower(str[d + i]))
		{
			return false;
		}
	}
	return true;
}

bool AffinityPrivate::Load(const std::string& file_name, Driver* driver)
{
	Clear();

	if (driver == nullptr)
	{
		error_msg = "driver is null";
		return false;
	}

	archive = new AffinityReader::Archive(driver);
	reader  = new AffinityReader::Reader;
	cpp     = new AffinityReader::Cpp;

	if (!archive->Load(file_name))
	{
		error_msg = archive->GetErrorMessage();
		return false;
	}

	std::string doc_name;

	if (EndsWith(file_name, ".afdesign") || EndsWith(file_name, ".afphoto") || EndsWith(file_name, ".afpub") ||
	    EndsWith(file_name, ".aftemplate"))
	{
		type     = Affinity::Type::Pers;
		doc_name = "doc.dat";
	} else if (EndsWith(file_name, ".dat"))
	{
		type     = Affinity::Type::Pref;
		doc_name = "preferences";
	} else if (EndsWith(file_name, ".propcol"))
	{
		type     = Affinity::Type::PCFl;
		doc_name = "structure";
	} else
	{
		error_msg = "unknown file";
		return false;
	}

	const auto* rev = archive->GetHeadFileRevision(doc_name);

	if (rev == nullptr || rev->GetCompressedSize() == 0u)
	{
		error_msg = "file not found: " + doc_name;
		return false;
	}

	// printf("%s [%d -> %d]\n", doc_name.c_str(), static_cast<int>(rev->GetCompressedSize()), static_cast<int>(rev->GetSize()));

	AffinityReader::ByteBuffer buf;

	if (!archive->Extract(rev, &buf))
	{
		error_msg = archive->GetErrorMessage();
		return false;
	}

	if (!reader->Load(buf))
	{
		error_msg = reader->GetErrorMessage();
		return false;
	}

	switch (type)
	{
		case Affinity::Type::PCFl: pcfl = cpp->CreatePCFl(reader->GetDoc()); break;
		case Affinity::Type::Pers: pers = cpp->CreatePers(reader->GetDoc()); break;
		case Affinity::Type::Pref: pref = cpp->CreatePref(reader->GetDoc()); break;
		default: error_msg = "unknown file"; return false;
	}

	return true;
}

std::string AffinityPrivate::GetErrMsg() const
{
	return error_msg;
}

void AffinityPrivate::Clear()
{
	if (cpp != nullptr)
	{
		delete cpp;
		cpp = nullptr;
	}

	if (reader != nullptr)
	{
		delete reader;
		reader = nullptr;
	}

	if (archive != nullptr)
	{
		delete archive;
		archive = nullptr;
	}

	type = Affinity::Type::Unknown;
	pcfl = nullptr;
	pers = nullptr;
	pref = nullptr;
}

Affinity::Affinity(): m_pimpl(new AffinityPrivate) {}

Affinity::~Affinity()
{
	m_pimpl->Clear();
	delete m_pimpl;
}

bool Affinity::Load(const std::string& file_name, Driver* driver)
{
	return m_pimpl->Load(file_name, driver);
}

std::string Affinity::GetErrMsg() const
{
	return m_pimpl->GetErrMsg();
}

Affinity::Type Affinity::GetType() const
{
	return m_pimpl->type;
}

const AffinityReader::CppModel::PCFl* Affinity::GetPCFl() const
{
	return m_pimpl->pcfl;
}

const AffinityReader::CppModel::Pers* Affinity::GetPers() const
{
	return m_pimpl->pers;
}

const AffinityReader::CppModel::Pref* Affinity::GetPref() const
{
	return m_pimpl->pref;
}

const Archive* Affinity::GetArchive() const
{
	return m_pimpl->archive;
}

const Reader* Affinity::GetReader() const
{
	return m_pimpl->reader;
}

} // namespace AffinityReader
