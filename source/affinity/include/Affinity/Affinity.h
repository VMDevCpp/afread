// Copyright (c) 2020-2021 Vladimir Mamonov
// Licensed under the MIT license.

#ifndef AFFINITY_AFFINITY_H_
#define AFFINITY_AFFINITY_H_

#include "Affinity/Utils.h"

namespace AffinityReader {

namespace CppModel {
struct PCFl;
struct Pers;
struct Pref;
struct newD;
struct NGHS;
struct SynC;
struct SynP;
struct Auth;
struct Tmps;
} // namespace CppModel

class Driver;
class AffinityPrivate;
class Archive;
class Reader;

class Affinity
{
public:
	enum class Type
	{
		Unknown,
		PCFl,
		Pers,
		Pref,
		NewD,
		NGHS,
		SynC,
		SynP,
		Auth,
		Tmps
	};

	Affinity();
	virtual ~Affinity();

	AF_NO_COPY(Affinity);

	bool Load(const std::string& file_name, Driver* driver);

	[[nodiscard]] std::string GetErrMsg() const;

	[[nodiscard]] std::vector<Type> GetTypes() const;

	[[nodiscard]] const CppModel::PCFl* GetPCFl() const;
	[[nodiscard]] const CppModel::Pers* GetPers() const;
	[[nodiscard]] const CppModel::Pref* GetPref() const;
	[[nodiscard]] const CppModel::newD* GetnewD() const;
	[[nodiscard]] const CppModel::NGHS* GetNGHS() const;
	[[nodiscard]] const CppModel::SynC* GetSynC() const;
	[[nodiscard]] const CppModel::SynP* GetSynP() const;
	[[nodiscard]] const CppModel::Auth* GetAuth() const;
	[[nodiscard]] const CppModel::Tmps* GetTmps() const;

	[[nodiscard]] const Archive* GetArchive() const;
	[[nodiscard]] const Reader*  GetReader() const;

private:
	AffinityPrivate* m_pimpl;
};

} // namespace AffinityReader

#endif /* AFFINITY_AFFINITY_H_ */
