// Copyright (c) 2020 Vladimir Mamonov
// Licensed under the MIT license.

#ifndef AFFINITY_CPPPRIVATE_H
#define AFFINITY_CPPPRIVATE_H

#include "Affinity/Model.h"
#include "Affinity/Utils.h"

#include <unordered_map>

#define AF_CONSTRUCTOR(m) New_##m
#define AF_INIT(m)        Init_##m
#define AF_INIT_P(m)      Init_p_##m
#define AF_DESTRUCTOR(m)  Delete_##m

#define AF_DEFINE_CONSTRUCTOR(m) [[maybe_unused]] void* AF_CONSTRUCTOR(m)()
#define AF_DEFINE_INIT(m)        [[maybe_unused]] void AF_INIT(m)(CppPrivate * cpp, void* s, const Class* cls)
#define AF_DEFINE_DESTRUCTOR(m)  [[maybe_unused]] void AF_DESTRUCTOR(m)(void* ptr)

#define AF_NEW_INSTANCE(tt) static_cast<tt*>(cpp->NewInstance(&*v, AF_CONSTRUCTOR(tt), AF_INIT(tt), AF_DESTRUCTOR(tt)))

#define AF_STRUCT_INIT(m)                                                                                                                  \
	static void AF_INIT_P(m)([[maybe_unused]] CppPrivate * cpp, [[maybe_unused]] m * s, [[maybe_unused]] const Class* cls);                \
	void*       AF_CONSTRUCTOR(m)() { return new m {}; }                                                                                   \
	void        AF_DESTRUCTOR(m)(void* ptr) { delete static_cast<m*>(ptr); }                                                               \
	void        AF_INIT(m)(CppPrivate * cpp, void* s, const Class* cls) { AF_INIT_P(m)(cpp, static_cast<m*>(s), cls); }                    \
	static void AF_INIT_P(m)([[maybe_unused]] CppPrivate * cpp, [[maybe_unused]] m * s, [[maybe_unused]] const Class* cls)

#define AF_DEFINE(m)                                                                                                                       \
	AF_DEFINE_CONSTRUCTOR(m);                                                                                                              \
	AF_DEFINE_INIT(m);                                                                                                                     \
	AF_DEFINE_DESTRUCTOR(m);

#define AF_INIT_BASE(tt) AF_INIT(tt)(cpp, static_cast<tt*>(s), cls)

#define AF_INIT_S(ss, uu, tt)     ReadValueS<tt>(cls, uu, &s->ss);
#define AF_INIT_A(ss, uu, tt, aa) ReadValueA<tt, aa>(cls, uu, &s->ss);
#define AF_INIT_V(ss, uu, tt)     ReadValueV<tt>(cls, uu, &s->ss)
#define AF_INIT_N(ss)             s->ss = nullptr;
#define AF_INIT_E(ss)             s->ss.clear();
#define AF_INIT_C(ss, uu, tt)                                                                                                              \
	if (const auto* f = cls->GetFields().Find(uu); f != nullptr && f->value.IsType<AffinityReader::SharedPtr<Class>>())                    \
	{                                                                                                                                      \
		const auto& v = f->value.GetValue<AffinityReader::SharedPtr<Class>>();                                                             \
		s->ss         = AF_NEW_INSTANCE(tt);                                                                                               \
	}
#define AF_INIT_L(ss, uu, tt)                                                                                                              \
	if (const auto* f = cls->GetFields().Find(uu);                                                                                         \
	    f != nullptr && f->value.IsType<AffinityReader::SharedArray<AffinityReader::SharedPtr<Class>>>())                                  \
	{                                                                                                                                      \
		const auto& vs = f->value.GetValue<AffinityReader::SharedArray<AffinityReader::SharedPtr<Class>>>();                               \
		for (const auto& v: vs)                                                                                                            \
		{                                                                                                                                  \
			auto* inst = AF_NEW_INSTANCE(tt);                                                                                              \
			if (inst != nullptr)                                                                                                           \
			{                                                                                                                              \
				s->ss.push_back(inst);                                                                                                     \
			}                                                                                                                              \
		}                                                                                                                                  \
	}
#define AF_INIT_M(uu, sw)                                                                                                                  \
	if (const auto* f = cls->GetFields().Find(uu); f != nullptr && f->value.IsType<AffinityReader::SharedPtr<Class>>())                    \
	{                                                                                                                                      \
		const auto& v = f->value.GetValue<AffinityReader::SharedPtr<Class>>();                                                             \
		switch (v->GetType())                                                                                                              \
			sw;                                                                                                                            \
	}
#define AF_CASE_M(ss, uu, tt)                                                                                                              \
	case uu:                                                                                                                               \
	{                                                                                                                                      \
		auto* inst = AF_NEW_INSTANCE(tt);                                                                                                  \
		if (inst != nullptr)                                                                                                               \
		{                                                                                                                                  \
			inst->base_type = tt::Type::tt;                                                                                                \
		}                                                                                                                                  \
		s->ss = inst;                                                                                                                      \
	}                                                                                                                                      \
	break
#define AF_INIT_X(uu, sw)                                                                                                                  \
	if (const auto* f = cls->GetFields().Find(uu);                                                                                         \
	    f != nullptr && f->value.IsType<AffinityReader::SharedArray<AffinityReader::SharedPtr<Class>>>())                                  \
	{                                                                                                                                      \
		const auto& vs = f->value.GetValue<AffinityReader::SharedArray<AffinityReader::SharedPtr<Class>>>();                               \
		for (const auto& v: vs)                                                                                                            \
		{                                                                                                                                  \
			switch (v->GetType())                                                                                                          \
				sw;                                                                                                                        \
		}                                                                                                                                  \
	}
#define AF_CASE_X(ss, uu, tt)                                                                                                              \
	case uu:                                                                                                                               \
	{                                                                                                                                      \
		auto* inst = AF_NEW_INSTANCE(tt);                                                                                                  \
		if (inst != nullptr)                                                                                                               \
		{                                                                                                                                  \
			inst->base_type = tt::Type::tt;                                                                                                \
			s->ss.push_back(inst);                                                                                                         \
		}                                                                                                                                  \
	}                                                                                                                                      \
	break

namespace AffinityReader {

template <class T, class O>
void ReadValueS(const Class* cls, uint32_t tag, O* out)
{
	if (const auto* f = cls->GetFields().Find(tag); f != nullptr && f->value.IsType<T>())
	{
		*out = f->value.GetValue<T>();
	}
}

template <class T, int N, class O>
void ReadValueA(const Class* cls, uint32_t tag, O* out)
{
	if (const auto* f = cls->GetFields().Find(tag); f != nullptr && f->value.IsType<T>())
	{
		const auto& v = f->value.GetValue<T>();
		for (int i = 0; i < N; i++)
		{
			(*out)[i] = v[i];
		}
	}
}

template <class T, class O>
void ReadValueV(const Class* cls, uint32_t tag, O* out)
{
	if (const auto* f = cls->GetFields().Find(tag); f != nullptr && f->value.IsType<T>())
	{
		const auto& vs = f->value.GetValue<T>();
		out->reserve(vs.Size());
		for (const auto& v: vs)
		{
			out->push_back(v);
		}
	}
}

class CppPrivate
{
public:
	using constructor_func_t = void* (*)();
	using destructor_func_t  = void (*)(void*);
	using init_func_t        = void (*)(CppPrivate*, void*, const Class*);

	CppPrivate() = default;
	virtual ~CppPrivate();

	AF_NO_COPY(CppPrivate);

	void Clear();

	void* NewInstance(const Class* cls, constructor_func_t constructor, init_func_t init, destructor_func_t destructor);

private:
	struct ClassInstance
	{
		void*             instance;
		destructor_func_t destructor;
	};

	std::vector<ClassInstance>           m_classes;
	std::unordered_map<uint32_t, size_t> m_map;
};

} // namespace AffinityReader

#endif /* AFFINITY_CPPPRIVATE_H */
