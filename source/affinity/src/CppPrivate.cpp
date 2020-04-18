// Copyright (c) 2020 Vladimir Mamonov
// Licensed under the MIT license.

#include "Affinity/CppPrivate.h"

#include "Affinity/Model.h"

#include <memory>
#include <utility>

namespace AffinityReader {

CppPrivate::~CppPrivate()
{
	Clear();
}

void CppPrivate::Clear()
{
	for (auto& inst: m_classes)
	{
		inst.destructor(inst.instance);
	}
	m_classes.clear();
	m_map.clear();
}

void* CppPrivate::NewInstance(const Class* cls, constructor_func_t constructor, init_func_t init, destructor_func_t destructor)
{
	auto status = cls->GetClassStatus();

	switch (status)
	{
		case ClassStatus::Root:
		case ClassStatus::NonShared:
		{
			void*         ret = constructor();
			ClassInstance inst {};
			inst.instance   = ret;
			inst.destructor = destructor;
			m_classes.push_back(inst);
			init(this, ret, cls);
			return ret;
		}

		case ClassStatus::Link:
		{
			auto id = cls->GetId();
			auto f  = m_map.find(id);
			if (f == m_map.end())
			{
				return nullptr;
			}
			return m_classes[f->second].instance;
		}

		case ClassStatus::Shared:
		{
			void*         ret = constructor();
			ClassInstance inst {};
			inst.instance   = ret;
			inst.destructor = destructor;
			auto index      = m_classes.size();
			m_classes.push_back(inst);
			auto id   = cls->GetId();
			m_map[id] = index;
			init(this, ret, cls);
			return ret;
		}

		case ClassStatus::Null:
		case ClassStatus::Invalid:
		default: return nullptr;
	}
}

} // namespace AffinityReader
