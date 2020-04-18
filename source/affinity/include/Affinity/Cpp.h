// Copyright (c) 2020 Vladimir Mamonov
// Licensed under the MIT license.

#ifndef AFFINITY_CPP_H
#define AFFINITY_CPP_H

#include "Affinity/Utils.h"

namespace AffinityReader {

namespace CppModel {
struct PCFl;
struct Pers;
struct Pref;
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

private:
	CppPrivate* m_pimpl;
};

} // namespace AffinityReader

#endif /* AFFINITY_CPP_H */
