// Copyright (c) 2020-2021 Vladimir Mamonov
// Licensed under the MIT license.

#include "Affinity/Affinity.h"

#include "Affinity/Archive.h"
#include "Affinity/Cpp.h"
#include "Affinity/Reader.h"

namespace AffinityReader {

class AffinityPrivate
{
public:
	void                      Clear();
	bool                      Load(const std::string& file_name, Driver* driver);
	[[nodiscard]] std::string GetErrMsg() const;

	std::vector<Affinity::Type>     types;
	AffinityReader::CppModel::PCFl* pcfl = {nullptr};
	AffinityReader::CppModel::Pers* pers = {nullptr};
	AffinityReader::CppModel::Pref* pref = {nullptr};
	AffinityReader::CppModel::newD* newd = {nullptr};
	AffinityReader::CppModel::NGHS* nghs = {nullptr};
	AffinityReader::CppModel::SynC* sync = {nullptr};
	AffinityReader::CppModel::SynP* synp = {nullptr};
	AffinityReader::CppModel::Auth* auth = {nullptr};
	AffinityReader::CppModel::Tmps* tmps = {nullptr};

	AffinityReader::Archive*          archive = {nullptr};
	AffinityReader::Reader*           reader  = {nullptr};
	std::vector<AffinityReader::Cpp*> cpps;

	std::string error_msg;
};

bool AffinityPrivate::Load(const std::string& file_name, Driver* driver)
{
	struct DocInfo
	{
		const char*    doc_name;
		Affinity::Type type;
	};

	static const DocInfo doc_infos[] = {
	    {"doc.dat", Affinity::Type::Pers},          {"preferences", Affinity::Type::Pref}, {"structure", Affinity::Type::PCFl},
	    {"newdoccontroller", Affinity::Type::NewD}, {"newdocstate", Affinity::Type::NGHS}, {"content.dat", Affinity::Type::SynC},
	    {"previews.dat", Affinity::Type::SynP},     {"session.dat", Affinity::Type::Auth}, {"templates.dat", Affinity::Type::Tmps}};

	Clear();

	if (driver == nullptr)
	{
		error_msg = "driver is null";
		return false;
	}

	archive = new AffinityReader::Archive(driver);
	reader  = new AffinityReader::Reader;

	if (!archive->Load(file_name))
	{
		error_msg = archive->GetErrorMessage();
		return false;
	}

	for (const auto& info: doc_infos)
	{
		std::string doc_name = info.doc_name;
		auto        type     = info.type;

		const auto* rev = archive->GetHeadFileRevision(doc_name);

		if (rev == nullptr || rev->GetCompressedSize() == 0u)
		{
			continue;
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

		auto* cpp = new AffinityReader::Cpp;
		cpps.push_back(cpp);

		switch (type)
		{
			case Affinity::Type::PCFl: pcfl = cpp->CreatePCFl(reader->GetDoc()); break;
			case Affinity::Type::Pers: pers = cpp->CreatePers(reader->GetDoc()); break;
			case Affinity::Type::Pref: pref = cpp->CreatePref(reader->GetDoc()); break;
			case Affinity::Type::NewD: newd = cpp->CreatenewD(reader->GetDoc()); break;
			case Affinity::Type::NGHS: nghs = cpp->CreateNGHS(reader->GetDoc()); break;
			case Affinity::Type::SynC: sync = cpp->CreateSynC(reader->GetDoc()); break;
			case Affinity::Type::SynP: synp = cpp->CreateSynP(reader->GetDoc()); break;
			case Affinity::Type::Auth: auth = cpp->CreateAuth(reader->GetDoc()); break;
			case Affinity::Type::Tmps: tmps = cpp->CreateTmps(reader->GetDoc()); break;
			default: error_msg = "unknown file"; return false;
		}

		types.push_back(type);
	}

	return true;
}

std::string AffinityPrivate::GetErrMsg() const
{
	return error_msg;
}

void AffinityPrivate::Clear()
{
	for (auto* cpp: cpps)
	{
		if (cpp != nullptr)
		{
			delete cpp;
			cpp = nullptr;
		}
	}
	cpps.clear();

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

	types.clear();

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

std::vector<Affinity::Type> Affinity::GetTypes() const
{
	return m_pimpl->types;
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

const AffinityReader::CppModel::newD* Affinity::GetnewD() const
{
	return m_pimpl->newd;
}

const AffinityReader::CppModel::NGHS* Affinity::GetNGHS() const
{
	return m_pimpl->nghs;
}

const AffinityReader::CppModel::SynC* Affinity::GetSynC() const
{
	return m_pimpl->sync;
}

const AffinityReader::CppModel::SynP* Affinity::GetSynP() const
{
	return m_pimpl->synp;
}

const AffinityReader::CppModel::Auth* Affinity::GetAuth() const
{
	return m_pimpl->auth;
}

const AffinityReader::CppModel::Tmps* Affinity::GetTmps() const
{
	return m_pimpl->tmps;
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
