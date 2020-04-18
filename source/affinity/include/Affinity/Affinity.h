// Copyright (c) 2020 Vladimir Mamonov
// Licensed under the MIT license.

#ifndef AFFINITY_AFFINITY_H_
#define AFFINITY_AFFINITY_H_

#include "Affinity/Utils.h"

namespace AffinityReader {

namespace CppModel {
struct PCFl;
struct Pers;
struct Pref;
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
		Pref
	};

	Affinity();
	virtual ~Affinity();

	AF_NO_COPY(Affinity);

	bool Load(const std::string& file_name, Driver* driver);

	[[nodiscard]] std::string GetErrMsg() const;

	[[nodiscard]] Type GetType() const;

	[[nodiscard]] const CppModel::PCFl* GetPCFl() const;
	[[nodiscard]] const CppModel::Pers* GetPers() const;
	[[nodiscard]] const CppModel::Pref* GetPref() const;

	[[nodiscard]] const Archive* GetArchive() const;
	[[nodiscard]] const Reader*  GetReader() const;

private:
	AffinityPrivate* m_pimpl;
};

} // namespace AffinityReader

#endif /* AFFINITY_AFFINITY_H_ */
