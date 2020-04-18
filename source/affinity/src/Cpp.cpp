// Copyright (c) 2020 Vladimir Mamonov
// Licensed under the MIT license.

#include "Affinity/Cpp.h"

#include "Affinity/CppPrivate.h"

namespace AffinityReader {

namespace CppModel {
AF_DEFINE(PCFl);
AF_DEFINE(Pers);
AF_DEFINE(Pref);
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

} // namespace AffinityReader
