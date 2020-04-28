// Copyright (c) 2020 Vladimir Mamonov
// Licensed under the MIT license.

#ifndef AFFINITY_MODEL_H
#define AFFINITY_MODEL_H

#include "Affinity/Utils.h"

#include <any>
#include <array>
#include <type_traits>
#include <unordered_map>
#include <utility>

namespace AffinityReader {

template <typename T>
class SharedPtr
{
public:
	explicit SharedPtr(T* ptr = nullptr) { m_ptr = new Ptr(ptr, 1); }

	SharedPtr(const SharedPtr<T>& p) noexcept
	{
		m_ptr = p.m_ptr;
		m_ptr->count++;
	}

	SharedPtr(SharedPtr<T>&& p) noexcept
	{
		m_ptr   = p.m_ptr;
		p.m_ptr = nullptr;
	}

	~SharedPtr()
	{
		if (m_ptr)
		{
			m_ptr->count--;
			if (m_ptr->count == 0)
			{
				delete m_ptr->ptr;
				delete m_ptr;
			}
		}
	}

	// NOLINTNEXTLINE(bugprone-unhandled-self-assignment,cert-oop54-cpp)
	SharedPtr<T>& operator=(const SharedPtr<T>& p)
	{
		if (this != &p)
		{
			this->~SharedPtr();
			m_ptr = p.m_ptr;
			m_ptr->count++;
		}
		return *this;
	}

	SharedPtr<T>& operator=(SharedPtr<T>&& p) noexcept
	{
		this->~SharedPtr();
		m_ptr   = p.m_ptr;
		p.m_ptr = nullptr;
		return *this;
	}

	T& operator*() const { return *m_ptr->ptr; }
	T* operator->() const { return m_ptr ? m_ptr->ptr : nullptr; }

	explicit operator bool() const { return m_ptr && m_ptr->ptr; }

private:
	struct Ptr
	{
		Ptr(T* p, int c): ptr(p), count(c) {}
		T*  ptr;
		int count;
	};

	Ptr* m_ptr;
};

template <typename T>
class SharedArray
{
public:
	explicit SharedArray(T* ptr, size_t size) { m_ptr = new Ptr(ptr, size, 1); }

	SharedArray(const SharedArray<T>& p) noexcept
	{
		m_ptr = p.m_ptr;
		m_ptr->count++;
	}

	SharedArray(SharedArray<T>&& p) noexcept
	{
		m_ptr   = p.m_ptr;
		p.m_ptr = nullptr;
	}

	~SharedArray()
	{
		if (m_ptr)
		{
			m_ptr->count--;
			if (m_ptr->count == 0)
			{
				delete[] m_ptr->ptr;
				delete m_ptr;
			}
		}
	}

	// NOLINTNEXTLINE(bugprone-unhandled-self-assignment,cert-oop54-cpp)
	SharedArray<T>& operator=(const SharedArray<T>& p)
	{
		if (this != &p)
		{
			this->~SharedArray();
			m_ptr = p.m_ptr;
			m_ptr->count++;
		}
		return *this;
	}

	SharedArray<T>& operator=(SharedArray<T>&& p) noexcept
	{
		this->~SharedArray();
		m_ptr   = p.m_ptr;
		p.m_ptr = nullptr;
		return *this;
	}

	T& operator*() const { return *m_ptr->ptr; }

	T* operator->() const { return m_ptr ? m_ptr->ptr : nullptr; }

	// NOLINTNEXTLINE(clang-analyzer-cplusplus.NewDelete)
	explicit operator bool() const { return m_ptr && m_ptr->ptr; }

	// NOLINTNEXTLINE(clang-analyzer-cplusplus.NewDelete)
	T& operator[](int index) const { return m_ptr->ptr[index]; }

	[[nodiscard]] size_t Size() const { return m_ptr ? m_ptr->size : 0; }

	using iterator       = T*;
	using const_iterator = const T*;

	// NOLINTNEXTLINE(readability-identifier-naming)
	iterator begin() { return m_ptr ? &m_ptr->ptr[0] : nullptr; }
	// NOLINTNEXTLINE(readability-identifier-naming)
	iterator end() { return m_ptr ? &m_ptr->ptr[m_ptr->size] : nullptr; }
	// NOLINTNEXTLINE(readability-identifier-naming)
	[[nodiscard]] const_iterator begin() const { return m_ptr ? &m_ptr->ptr[0] : nullptr; }
	// NOLINTNEXTLINE(readability-identifier-naming)
	[[nodiscard]] const_iterator end() const { return m_ptr ? &m_ptr->ptr[m_ptr->size] : nullptr; }
	// NOLINTNEXTLINE(readability-identifier-naming)
	[[nodiscard]] const_iterator cbegin() const { return m_ptr ? &m_ptr->ptr[0] : nullptr; }
	// NOLINTNEXTLINE(readability-identifier-naming)
	[[nodiscard]] const_iterator cend() const { return m_ptr ? &m_ptr->ptr[m_ptr->size] : nullptr; }

private:
	struct Ptr
	{
		Ptr(T* p, size_t s, int c): ptr(p), size(s), count(c) {}
		T*     ptr;
		size_t size;
		int    count;
	};

	Ptr* m_ptr;
};

struct DocFormat
{
	uint32_t file_tag;
	uint16_t file_ver;
	uint32_t type_tag;
	uint16_t type_ver;
	uint32_t version;
};

template <int N>
using vec_f_t = std::array<float, N>;

template <int N>
using vec_d_t = std::array<double, N>;

template <int N>
using vec_i_t = std::array<int32_t, N>;

template <class D, int N, class U, int M>
struct CurveT
{
	D d[N];
	U u[M];
};

using curve12_t = CurveT<double, 1, uint8_t, 4>;
using curve16_t = CurveT<double, 1, uint32_t, 2>;
using curve18_t = CurveT<double, 2, uint8_t, 2>;

template <class D, int N, int = 0>
struct ColorT
{
	D c[N];
};

using Color32   = ColorT<uint8_t, 4>;
using ColorRGBA = ColorT<float, 4, 1>;
using ColorHSLA = ColorT<float, 4, 2>;
using ColorLABA = ColorT<uint16_t, 4>;
using ColorCMYK = ColorT<float, 5>;
using ColorGRAY = ColorT<float, 2>;

struct EnumT
{
	[[nodiscard]] uint64_t Id() const { return (static_cast<uint64_t>(version) << 32u) | (static_cast<uint64_t>(id)); }

	int id;
	int version;
};

struct FlagsT
{
	uint64_t flags;
	int      version;
};

struct EmbeddedData
{
	uint32_t    tag;
	uint32_t    size;
	std::string data;
};

struct BinaryData
{
	ByteBuffer buf;
};

class Class;

struct Type
{
	template <class T>
	struct Get
	{
		static int Id()
		{
			static int id = NextId()++;
			return id;
		}
	};

private:
	static int& NextId()
	{
		static int i = 0;
		return i;
	}
};

class Variant final
{
private:
	template <typename T>
	using IsNotVariant = typename std::enable_if<!std::is_same<typename std::remove_reference<T>::type, Variant>::value>::type;

public:
	Variant()  = default;
	~Variant() = default;

	template <class T, typename = IsNotVariant<T>>
	explicit Variant(const T& src): m_any(src), m_type(Type::Get<typename std::remove_reference<T>::type>::Id())
	{
	}

	template <class T, typename = IsNotVariant<T>>
	Variant& operator=(const T& src)
	{
		m_type = Type::Get<typename std::remove_reference<T>::type>::Id();
		m_any  = src;
		return *this;
	}

	template <class T, typename = IsNotVariant<T>>
	explicit Variant(T&& src): m_any(std::forward<T>(src)), m_type(Type::Get<typename std::remove_reference<T>::type>::Id())
	{
	}

	template <class T, typename = IsNotVariant<T>>
	Variant& operator=(T&& src)
	{
		m_type = Type::Get<typename std::remove_reference<T>::type>::Id();
		m_any  = std::forward<T>(src);
		return *this;
	}

	Variant(const Variant& src) = default;
	Variant& operator=(const Variant& src) = default;
	Variant(Variant&& src)                 = default;
	Variant& operator=(Variant&& src) = default;

	[[nodiscard]] const std::any& GetAny() const { return m_any; }
	[[nodiscard]] int             GetType() const { return m_type; }

	template <class T>
	[[nodiscard]] bool IsType() const
	{
		return (m_type == Type::Get<T>::Id());
	}

	template <class T>
	[[nodiscard]] const T& GetValue() const
	{
		return std::any_cast<const T&>(m_any);
	}

	template <class T>
	[[nodiscard]] const T* GetValuePtr() const
	{
		return std::any_cast<T>(&m_any);
	}

private:
	std::any m_any;
	int      m_type = -1;
};

struct Field
{
	void SetTag(uint32_t t)
	{
		no_tag = false;
		tag    = t;
	}

	bool     no_tag = {false};
	uint32_t tag    = {0};
	Class*   parent = {nullptr};
	int      count  = {0};
	Variant  value;
};

class FieldsList: public std::vector<Field>
{
public:
	using std::vector<Field>::vector;

	void push_back(const Field&) = delete;
	void push_back(Field&&)      = delete;

	[[nodiscard]] Field*       Find(uint32_t tag);
	[[nodiscard]] const Field* Find(uint32_t tag) const;

	void Add(const Field& f);
};

enum class ClassTypeStatus
{
	Invalid,
	Tag,
	TagId
};

struct ClassType
{
	ClassTypeStatus status = {ClassTypeStatus::Invalid};
	uint32_t        tag    = {0};
	uint16_t        id     = {0};
	Class*          parent = {nullptr};
};

enum class ClassStatus
{
	Invalid,
	Root,
	Link,
	Null,
	Shared,
	NonShared
};

class ClassHashmap: public std::unordered_map<uint32_t, Class*>
{
public:
	using std::unordered_map<uint32_t, Class*>::unordered_map;

	const Class* Find(uint32_t id);
};

class Class
{
public:
	Class()          = default;
	virtual ~Class() = default;

	void AddType(const ClassType& h) { m_types.push_back(h); }

	void                   SetLevel(int level) { m_level = level; }
	[[nodiscard]] int      GetLevel() const { return m_level; }
	[[nodiscard]] uint32_t GetId() const { return m_id; }
	void                   SetId(uint32_t id) { this->m_id = id; }

	FieldsList&                     GetFields() { return m_fields; }
	[[nodiscard]] const FieldsList& GetFields() const { return m_fields; }

	[[nodiscard]] const std::vector<ClassType>& GetTypes() const { return m_types; }

	[[nodiscard]] ClassStatus GetClassStatus() const { return m_class_status; }
	void                      SetClassStatus(ClassStatus class_status) { m_class_status = class_status; }

	[[nodiscard]] uint32_t GetType() const;
	void                   SetType(uint32_t tag);

	[[nodiscard]] const ClassHashmap* GetMap() const { return m_map; }
	[[nodiscard]] ClassHashmap*       GetMap() { return m_map; }
	void                              SetMap(ClassHashmap* map) { m_map = map; }

	AF_NO_COPY(Class);

private:
	ClassStatus            m_class_status = {ClassStatus::Invalid};
	uint32_t               m_id           = {0};
	int                    m_level        = {0};
	std::vector<ClassType> m_types;
	FieldsList             m_fields;
	ClassHashmap*          m_map = {nullptr};
};

class ClassConverter
{
public:
	static bool Convert30(Class* dst, uint32_t parent_tag, uint32_t field_tag, std::string* err_msg);
};

} // namespace AffinityReader

#endif /* AFFINITY_MODEL_H */
