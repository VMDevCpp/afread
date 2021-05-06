// Copyright (c) 2020-2021 Vladimir Mamonov
// Licensed under the MIT license.

#ifndef AFFINITY_CPP_H
#define AFFINITY_CPP_H

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

class CppPrivate;
class Class;

class Cpp
{
public:
	Cpp();
	virtual ~Cpp();

	AF_NO_COPY(Cpp);

	CppModel::PCFl* CreatePCFl(const Class* cls);
	CppModel::Pers* CreatePers(const Class* cls);
	CppModel::Pref* CreatePref(const Class* cls);
	CppModel::newD* CreatenewD(const Class* cls);
	CppModel::NGHS* CreateNGHS(const Class* cls);
	CppModel::SynC* CreateSynC(const Class* cls);
	CppModel::SynP* CreateSynP(const Class* cls);
	CppModel::Auth* CreateAuth(const Class* cls);
	CppModel::Tmps* CreateTmps(const Class* cls);

private:
	CppPrivate* m_pimpl;
};

} // namespace AffinityReader

#endif /* AFFINITY_CPP_H */
