// Copyright (c) 2020-2021 Vladimir Mamonov
// Licensed under the MIT license.

#include "Affinity/Cpp.h"

#include "Affinity/CppPrivate.h"

namespace AffinityReader {

namespace CppModel {
AF_DEFINE(PCFl);
AF_DEFINE(Pers);
AF_DEFINE(Pref);
AF_DEFINE(newD);
AF_DEFINE(NGHS);
AF_DEFINE(SynC);
AF_DEFINE(SynP);
AF_DEFINE(Auth);
AF_DEFINE(Tmps);
} // namespace CppModel

Cpp::Cpp(): m_pimpl(new CppPrivate) {}

Cpp::~Cpp()
{
	delete m_pimpl;
}

CppModel::PCFl* Cpp::CreatePCFl(const Class* cls)
{
	m_pimpl->Clear();
	return static_cast<CppModel::PCFl*>(
	    m_pimpl->NewInstance(cls, CppModel::AF_CONSTRUCTOR(PCFl), CppModel::AF_INIT(PCFl), CppModel::AF_DESTRUCTOR(PCFl)));
}

CppModel::Pers* Cpp::CreatePers(const Class* cls)
{
	m_pimpl->Clear();
	return static_cast<CppModel::Pers*>(
	    m_pimpl->NewInstance(cls, CppModel::AF_CONSTRUCTOR(Pers), CppModel::AF_INIT(Pers), CppModel::AF_DESTRUCTOR(Pers)));
}

CppModel::Pref* Cpp::CreatePref(const Class* cls)
{
	m_pimpl->Clear();
	return static_cast<CppModel::Pref*>(
	    m_pimpl->NewInstance(cls, CppModel::AF_CONSTRUCTOR(Pref), CppModel::AF_INIT(Pref), CppModel::AF_DESTRUCTOR(Pref)));
}

CppModel::newD* Cpp::CreatenewD(const Class* cls)
{
	m_pimpl->Clear();
	return static_cast<CppModel::newD*>(
	    m_pimpl->NewInstance(cls, CppModel::AF_CONSTRUCTOR(newD), CppModel::AF_INIT(newD), CppModel::AF_DESTRUCTOR(newD)));
}

CppModel::NGHS* Cpp::CreateNGHS(const Class* cls)
{
	m_pimpl->Clear();
	return static_cast<CppModel::NGHS*>(
	    m_pimpl->NewInstance(cls, CppModel::AF_CONSTRUCTOR(NGHS), CppModel::AF_INIT(NGHS), CppModel::AF_DESTRUCTOR(NGHS)));
}

CppModel::SynC* Cpp::CreateSynC(const Class* cls)
{
	m_pimpl->Clear();
	return static_cast<CppModel::SynC*>(
	    m_pimpl->NewInstance(cls, CppModel::AF_CONSTRUCTOR(SynC), CppModel::AF_INIT(SynC), CppModel::AF_DESTRUCTOR(SynC)));
}

CppModel::SynP* Cpp::CreateSynP(const Class* cls)
{
	m_pimpl->Clear();
	return static_cast<CppModel::SynP*>(
	    m_pimpl->NewInstance(cls, CppModel::AF_CONSTRUCTOR(SynP), CppModel::AF_INIT(SynP), CppModel::AF_DESTRUCTOR(SynP)));
}

CppModel::Auth* Cpp::CreateAuth(const Class* cls)
{
	m_pimpl->Clear();
	return static_cast<CppModel::Auth*>(
	    m_pimpl->NewInstance(cls, CppModel::AF_CONSTRUCTOR(Auth), CppModel::AF_INIT(Auth), CppModel::AF_DESTRUCTOR(Auth)));
}

CppModel::Tmps* Cpp::CreateTmps(const Class* cls)
{
	m_pimpl->Clear();
	return static_cast<CppModel::Tmps*>(
	    m_pimpl->NewInstance(cls, CppModel::AF_CONSTRUCTOR(Tmps), CppModel::AF_INIT(Tmps), CppModel::AF_DESTRUCTOR(Tmps)));
}

} // namespace AffinityReader
