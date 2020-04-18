// Copyright (c) 2020 Vladimir Mamonov
// Licensed under the MIT license.

#include "Affinity/Reader.h"

#include "Affinity/Json.h"
#include "Affinity/Model.h"

#include <cctype>
#include <cstdio>
#include <cwchar>
#include <memory>
#include <unordered_map>

#define AF_ERROR(s)                                                                                                                        \
	{                                                                                                                                      \
		SetError(__FILE__, __LINE__, s);                                                                                                   \
		return false;                                                                                                                      \
	}
#define AF_LOAD(v)                                                                                                                         \
	{                                                                                                                                      \
		if (!m_stream->Read(&(v), sizeof(v)))                                                                                              \
		{                                                                                                                                  \
			AF_ERROR("no more data");                                                                                                      \
		}                                                                                                                                  \
	}
#define AF_LOAD_S(v, size)                                                                                                                 \
	{                                                                                                                                      \
		if (!m_stream->Read(&(v), size))                                                                                                   \
		{                                                                                                                                  \
			AF_ERROR("no more data");                                                                                                      \
		}                                                                                                                                  \
	}
#if 1
#define AF_CHECK_V(t, v)                                                                                                                   \
	{                                                                                                                                      \
		if (!(v).IsType<t>()) AF_ERROR("invalid variant");                                                                                 \
		if ((v).GetValuePtr<t>() == nullptr) AF_ERROR("invalid variant");                                                                  \
	}
#define AF_CHECK_A(t, v)                                                                                                                   \
	{                                                                                                                                      \
		if (!(v).IsType<t>()) AF_ERROR("invalid variant");                                                                                 \
		if ((v).GetValuePtr<t>() == nullptr) AF_ERROR("invalid variant");                                                                  \
	}
#else
#define AF_CHECK_V(t, v)
#define AF_CHECK_A(t, v)
#endif

namespace AffinityReader {

constexpr int CLASS_STATUS_0 = 0;
constexpr int CLASS_STATUS_1 = 1;
constexpr int CLASS_STATUS_2 = 2;

constexpr int TYPE_STATUS_0 = 0;
constexpr int TYPE_STATUS_1 = 1;
constexpr int TYPE_STATUS_2 = 2;

class DocDat;

constexpr uint32_t TAG_DOC = 0x534bff00;

class DocDat: public Class, public ErrorHandler
{
public:
	bool Load(Stream* stream);

	DocFormat f {};
};

class ReaderPrivate: public ErrorHandler
{
public:
	ReaderPrivate();
	~ReaderPrivate() override;

	void Clear();
	bool Load(const ByteBuffer& buf);
	bool DbgDump() const;

	bool LoadClass30(Class* dst, const Field* field);
	bool LoadClass31(Class* dst);
	bool LoadClass32(Class* dst, ClassType* h);
	bool LoadFields(Class* parent, bool with_tag = true);

	template <class T>
	bool LoadField(Field* field, bool array, int type = 0);

	bool LoadCurve(Field* field, bool array);
	template <class T>
	bool LoadCurve(Field* field, bool array, uint32_t count);

	bool LoadColor(Field* field, bool array, int type);

	const Class*     GetDoc() const { return m_doc; }
	const DocFormat* GetDocFormat() const { return &m_doc->f; }

	AF_NO_COPY(ReaderPrivate);

private:
	DocDat*       m_doc    = {nullptr};
	Stream*       m_stream = {nullptr};
	ClassHashmap* m_map    = {nullptr};
};

bool DocDat::Load(Stream* m_stream)
{
	AF_LOAD(f.file_tag);

	if (f.file_tag != TAG_DOC)
	{
		AF_ERROR("unknown file format");
	}

	AF_LOAD(f.file_ver);
	AF_LOAD(f.type_tag);
	AF_LOAD(f.type_ver);

	if (f.file_ver > 2)
	{
		AF_ERROR("unknown file format");
	} else if (f.file_ver < 2)
	{
		f.version = 0;
	} else
	{
		AF_LOAD(f.version);
	}

	return true;
}

ReaderPrivate::ReaderPrivate()
{
	Clear();
}

ReaderPrivate::~ReaderPrivate()
{
	Clear();
}

void ReaderPrivate::Clear()
{
	delete m_doc;
	m_doc = nullptr;
	delete m_stream;
	m_stream = nullptr;
	delete m_map;
	m_map = nullptr;
	ResetError();
}

template <class T>
bool ReaderPrivate::LoadField(Field* field, bool array, int /*type*/)
{
	if (!array)
	{
		T value {};
		AF_LOAD(value);
		field->value = value;
		field->count = 1;
		AF_CHECK_V(T, field->value);
	} else
	{
		uint32_t count = 0;
		AF_LOAD(count);
		SharedArray<T> list = SharedArray<T>(count ? new T[count] : nullptr, count);
		for (uint32_t i = 0; i < count; i++)
		{
			AF_LOAD(list[i]);
		}
		field->value = list;
		field->count = count;
		AF_CHECK_A(SharedArray<T>, field->value);
	}
	return true;
}

bool ReaderPrivate::LoadColor(Field* field, bool array, int type)
{
	int size = type - 0x34;

	auto* parent = field->parent;

	if (parent == nullptr || parent->GetTypes().empty())
	{
		AF_ERROR("invalid parent class");
	}

	auto parent_tag = parent->GetTypes()[0].tag;
	auto field_tag  = field->tag;

	if (size == 4 && parent_tag == "BGrd"_tag && field_tag == "Colr"_tag)
	{
		return LoadField<Color32>(field, array);
	}
	if (size == 8 && parent_tag == "LABA"_tag && field_tag == "_col"_tag)
	{
		return LoadField<ColorLABA>(field, array);
	}
	if (size == 8 && parent_tag == "GRAY"_tag && field_tag == "_col"_tag)
	{
		return LoadField<ColorGRAY>(field, array);
	}
	if (size == 16 && parent_tag == "RGBA"_tag && field_tag == "_col"_tag)
	{
		return LoadField<ColorRGBA>(field, array);
	}
	if (size == 16 && parent_tag == "HSLA"_tag && field_tag == "_col"_tag)
	{
		return LoadField<ColorHSLA>(field, array);
	}
	if (size == 20 && parent_tag == "CMYK"_tag && field_tag == "_col"_tag)
	{
		return LoadField<ColorCMYK>(field, array);
	}

	AF_ERROR("unknown size and tags: " + std::to_string(size) + ", " + TagToString(parent_tag) + ", " + TagToString(field_tag));

	return true;
}

template <>
bool ReaderPrivate::LoadField<EmbeddedData>(Field* field, bool array, int /*type*/)
{
	EmbeddedData data {};

	if (array)
	{
		AF_ERROR("invalid data");
	}

	AF_LOAD(data.tag);
	AF_LOAD(data.size);

	ByteBuffer buf(data.size);
	AF_LOAD_S(*buf.data(), data.size);

	bool invalid = false;
	for (auto b: buf)
	{
		if (!((isalnum(static_cast<char>(b)) != 0) || static_cast<char>(b) == '/'))
		{
			invalid = true;
			break;
		}
	}

	if (invalid)
	{
		AF_ERROR("invalid data");
	}

	data.data = std::string(reinterpret_cast<const char*>(buf.data()), buf.size());

	field->value = data;
	field->count = 1;
	AF_CHECK_V(EmbeddedData, field->value);

	return true;
}

template <>
bool ReaderPrivate::LoadField<BinaryData>(Field* field, bool array, int /*type*/)
{
	uint32_t size = 0;

	if (array)
	{
		AF_ERROR("invalid data");
	}

	AF_LOAD(size);

	BinaryData data;
	data.buf.resize(size);
	AF_LOAD_S(*data.buf.data(), size);

	field->value = data;
	field->count = 1;
	AF_CHECK_V(BinaryData, field->value);

	return true;
}

template <>
bool ReaderPrivate::LoadField<Class*>(Field* field, bool array, int type)
{
	uint32_t  count = 1;
	ClassType h32;

	if (array)
	{
		AF_LOAD(count);

		if (type == 0x32)
		{
			AF_LOAD(h32.tag);
			AF_LOAD(h32.id);
		}
	}

	SharedArray<SharedPtr<Class>> clss    = SharedArray<SharedPtr<Class>>(count != 0U ? new SharedPtr<Class>[count] : nullptr, count);
	bool                          invalid = false;

	for (uint32_t i = 0; i < count; i++)
	{
		auto* cls = new Class();
		clss[i]   = SharedPtr<Class>(cls);

		cls->SetLevel(field->parent->GetLevel() + (array ? 2 : 1));
		cls->SetMap(m_map);

		switch (type)
		{
			case 0x30: invalid = !LoadClass30(cls, field); break;
			case 0x31: invalid = !LoadClass31(cls); break;
			case 0x32: invalid = !LoadClass32(cls, (array ? &h32 : nullptr)); break;
			default: invalid = true; break;
		}

		if (invalid)
		{
			break;
		}
	}

	if (!array)
	{
		field->value = (clss ? clss[0] : SharedPtr<Class>(nullptr));
		field->count = 1;
		AF_CHECK_V(SharedPtr<Class>, field->value);
	} else
	{
		field->value = clss;
		field->count = count;
		AF_CHECK_A(SharedArray<SharedPtr<Class>>, field->value);
	}

	return !invalid;
}

bool ReaderPrivate::LoadCurve(Field* field, bool array)
{
	uint32_t count = 1;
	uint16_t size  = 0;

	if (array)
	{
		AF_LOAD(count);
	}
	AF_LOAD(size);

	switch (size)
	{
		case 12: return LoadCurve<curve12_t>(field, array, count);
		case 16: return LoadCurve<curve16_t>(field, array, count);
		case 18: return LoadCurve<curve18_t>(field, array, count);

		default: AF_ERROR("unknown curve");
	}

	return true;
}

template <class T>
bool ReaderPrivate::LoadCurve(Field* field, bool array, uint32_t count)
{
	SharedArray<T> clss = SharedArray<T>(count != 0U ? new T[count] : nullptr, count);

	for (uint32_t i = 0; i < count; i++)
	{
		T cls {};

		AF_LOAD(cls.d);
		AF_LOAD(cls.u);

		clss[i] = cls;
	}

	if (!array)
	{
		field->value = (clss ? clss[0] : T());
		field->count = 1;
		AF_CHECK_V(T, field->value);
	} else
	{
		field->value = clss;
		field->count = count;
		AF_CHECK_A(SharedArray<T>, field->value);
	}

	return true;
}

template <>
bool ReaderPrivate::LoadField<FlagsT>(Field* field, bool array, int /*type*/)
{
	if (array)
	{
		AF_ERROR("invalid flags");
	}

	uint16_t version = 0;
	uint8_t  count   = 0;
	uint64_t flags   = 0;

	AF_LOAD(version);
	AF_LOAD(count);

	if (count > 8)
	{
		AF_ERROR("invalid count");
	}

	AF_LOAD_S(flags, count);

	FlagsT f {};
	f.version = version;
	f.flags   = flags;

	field->value = f;
	field->count = 1;
	AF_CHECK_V(FlagsT, field->value);

	return true;
}

template <>
bool ReaderPrivate::LoadField<EnumT>(Field* field, bool array, int /*type*/)
{
	uint16_t v1 = 0;
	uint16_t v2 = 0;

	if (!array)
	{
		AF_LOAD(v1);
		AF_LOAD(v2);
		EnumT e {};
		e.id         = v1;
		e.version    = v2;
		field->value = e;
		field->count = 1;
		AF_CHECK_V(EnumT, field->value);
	} else
	{
		uint32_t count = 0;
		AF_LOAD(count);
		AF_LOAD(v2);
		SharedArray<EnumT> list = SharedArray<EnumT>(count != 0U ? new EnumT[count] : nullptr, count);
		for (uint32_t i = 0; i < count; i++)
		{
			AF_LOAD(v1);
			list[i].id      = v1;
			list[i].version = v2;
		}
		field->value = list;
		field->count = count;
		AF_CHECK_A(SharedArray<EnumT>, field->value);
	}

	return true;
}

template <>
bool ReaderPrivate::LoadField<bool>(Field* field, bool array, int /*type*/)
{
	if (array)
	{
		uint32_t count = 0;
		AF_LOAD(count);
		SharedArray<bool> bools = SharedArray<bool>(count != 0U ? new bool[count] : nullptr, count);

		uint32_t c1    = count / 8;
		uint32_t c2    = count % 8;
		int      index = 0;
		uint8_t  b     = 0;

		while ((c1--) != 0)
		{
			AF_LOAD(b);
			for (uint8_t i = 0; i < 8; i++)
			{
				bools[index++] = !((uint8_t(b >> i) & 1U) == 0);
			}
		}
		if (c2 != 0)
		{
			uint8_t mask = 1;
			AF_LOAD(b);
			do
			{
				bools[index++] = !((b & mask) == 0);
				mask *= 2;
			} while ((--c2) != 0);
		}
		field->value = SharedArray<bool>(bools);
		field->count = count;
		AF_CHECK_A(SharedArray<bool>, field->value);
	} else
	{
		uint8_t b = 0;
		AF_LOAD(b);

		field->value = !(b == 0U);
		field->count = 1;
		AF_CHECK_V(bool, field->value);
	}
	return true;
}

template <>
bool ReaderPrivate::LoadField<std::string>(Field* field, bool array, int /*type*/)
{
	if (!array)
	{
		uint32_t    length = 0;
		std::string str;
		AF_LOAD(length);
		AF_LOAD_S(str, length);
		field->value = str;
		field->count = 1;
		AF_CHECK_V(std::string, field->value);
	} else
	{
		uint32_t total_size = 0;
		uint32_t count      = 0;
		AF_LOAD(total_size);
		AF_LOAD(count);
		SharedArray<std::string> strs = SharedArray<std::string>(count != 0U ? new std::string[count] : nullptr, count);
		for (uint32_t i = 0; i < count; i++)
		{
			uint32_t length = 0;
			AF_LOAD(length);
			AF_LOAD_S(strs[i], length);
		}
		field->value = strs;
		field->count = count;
		AF_CHECK_A(SharedArray<std::string>, field->value);
	}
	return true;
}

bool ReaderPrivate::LoadFields(Class* parent, bool with_tag)
{
	uint8_t type   = 0;
	auto&   fields = parent->GetFields();

	for (;;)
	{
		auto pos = m_stream->GetPos();

		AF_LOAD(type);
		bool array = !((type & 0x80U) == 0);
		type &= 0x7fU;

		if (type == 0x00)
		{
			return true;
		}

		if (type > 0x77)
		{
			AF_ERROR("invalid type at " + std::to_string(pos));
		}

		Field field;
		field.tag    = 0;
		field.parent = parent;
		field.no_tag = !with_tag;

		if (with_tag)
		{
			AF_LOAD(field.tag);
		}

		bool ok       = false;
		bool unknown  = false;
		bool need_tag = false;

		// printf("%d : %s, %02" PRIx8"\n", (int)pos, TagToString(field.tag).c_str(), type);

		switch (type)
		{
			case 0x29: ok = LoadField<bool>(&field, array); break;

			case 0x2a: ok = LoadField<EnumT>(&field, array); break;

			case 0x2b:
			case 0x2e: ok = LoadField<std::string>(&field, array); break;

			case 0x2c: ok = LoadCurve(&field, array); break;
			case 0x2d: ok = LoadField<BinaryData>(&field, array); break;

			case 0x30:
			case 0x31:
			case 0x32:
				need_tag = true;
				ok       = with_tag && LoadField<Class*>(&field, array, type);
				break;

			case 0x33:
				need_tag = true;
				ok       = with_tag && LoadField<EmbeddedData>(&field, array);
				break;

			case 0x75:
				need_tag = true;
				ok       = with_tag && LoadField<FlagsT>(&field, array);
				break;

			case 0x76:
			case 0x77:
				need_tag = true;
				unknown  = true;
				break;

			case 0x2f: /*ok = LoadField<uint32_t>(&field, array); break;*/
			case 0x34: ok = LoadField<uint32_t>(&field, array); break;

			case 0x01: ok = LoadField<uint8_t>(&field, array); break;
			case 0x02: ok = LoadField<uint16_t>(&field, array); break;
			case 0x03: ok = LoadField<uint32_t>(&field, array); break;
			case 0x04: ok = LoadField<uint64_t>(&field, array); break;
			case 0x05: ok = LoadField<int8_t>(&field, array); break;
			case 0x06: ok = LoadField<int16_t>(&field, array); break;
			case 0x07: ok = LoadField<int32_t>(&field, array); break;
			case 0x08: ok = LoadField<int64_t>(&field, array); break;
			case 0x09: ok = LoadField<float>(&field, array); break;
			case 0x0a: ok = LoadField<double>(&field, array); break;

			case 0x15: ok = LoadField<vec_i_t<2>>(&field, array); break;
			case 0x16: ok = LoadField<vec_i_t<3>>(&field, array); break;
			case 0x17: ok = LoadField<vec_i_t<4>>(&field, array); break;
			case 0x18: ok = LoadField<vec_i_t<5>>(&field, array); break;
			case 0x19: ok = LoadField<vec_i_t<6>>(&field, array); break;

			case 0x1f: ok = LoadField<vec_f_t<2>>(&field, array); break;
			case 0x20: ok = LoadField<vec_f_t<3>>(&field, array); break;
			case 0x21: ok = LoadField<vec_f_t<4>>(&field, array); break;
			case 0x22: ok = LoadField<vec_f_t<5>>(&field, array); break;
			case 0x23: ok = LoadField<vec_f_t<6>>(&field, array); break;
			case 0x24: ok = LoadField<vec_d_t<2>>(&field, array); break;
			case 0x25: ok = LoadField<vec_d_t<3>>(&field, array); break;
			case 0x26: ok = LoadField<vec_d_t<4>>(&field, array); break;
			case 0x27: ok = LoadField<vec_d_t<5>>(&field, array); break;
			case 0x28: ok = LoadField<vec_d_t<6>>(&field, array); break;

			default:
				if (type >= 0x35 && type <= 0x74)
				{
					ok = LoadColor(&field, array, type);
				} else
				{
					unknown = true;
				}
				break;
		}

		if (need_tag && !with_tag)
		{
			AF_ERROR("missing tag at " + std::to_string(pos));
		}

		if (!unknown)
		{
			fields.Add(field);
		} else
		{
			AF_ERROR("unknown type at " + std::to_string(pos));
		}

		if (!ok)
		{
			return false;
		}
	}

	return true;
}

bool ReaderPrivate::LoadClass30(Class* dst, const Field* field)
{
	dst->SetClassStatus(ClassStatus::NonShared);
	dst->SetId(0);

	if (!LoadFields(dst, false))
	{
		return false;
	}

	auto* parent = field->parent;

	if (parent == nullptr || parent->GetTypes().empty())
	{
		AF_ERROR("invalid parent class");
	}

	auto parent_tag = parent->GetTypes()[0].tag;
	auto field_tag  = field->tag;

	std::string err_msg;

	if (!ClassConverter::Convert30(dst, parent_tag, field_tag, &err_msg))
	{
		AF_ERROR(err_msg);
	}

	return true;
}

bool ReaderPrivate::LoadClass31(Class* dst)
{
	auto    pos  = m_stream->GetPos();
	uint8_t flag = 0;
	AF_LOAD(flag);

	if (flag == CLASS_STATUS_1)
	{
		dst->SetClassStatus(ClassStatus::Shared);

		uint32_t id = 0;
		AF_LOAD(id);
		dst->SetId(id);

		auto* map = dst->GetMap();
		if (map != nullptr)
		{
			if (map->Find(id) != nullptr)
			{
				AF_ERROR("invalid id");
			}
			(*map)[id] = dst;
		}

		bool end = false;
		do
		{
			uint8_t type_flag = 0;

			ClassType h;
			h.tag    = 0;
			h.id     = 0;
			h.parent = dst;
			auto pos = m_stream->GetPos();
			AF_LOAD(type_flag);

			if (type_flag == TYPE_STATUS_1)
			{
				AF_LOAD(h.tag);
				h.status = ClassTypeStatus::Tag;
				end      = true;
			} else if (type_flag == TYPE_STATUS_2)
			{
				end = true;
			} else if (type_flag == TYPE_STATUS_0)
			{
				AF_LOAD(h.tag);
				AF_LOAD(h.id);
				if (!LoadFields(h.parent))
				{
					return false;
				}
				h.status = ClassTypeStatus::TagId;
			} else
			{
				AF_ERROR("unknown flag at " + std::to_string(pos));
			}

			if (type_flag != TYPE_STATUS_2)
			{
				dst->AddType(h);
			}
		} while (!end);

		if (!LoadFields(dst))
		{
			return false;
		}
	} else if (flag == CLASS_STATUS_2)
	{
		dst->SetClassStatus(ClassStatus::Link);

		uint32_t id = 0;
		AF_LOAD(id);
		dst->SetId(id);

		auto* map = dst->GetMap();
		if (map != nullptr)
		{
			if (map->Find(id) == nullptr)
			{
				AF_ERROR("invalid id");
			}
		}
	} else if (flag == CLASS_STATUS_0)
	{
		dst->SetClassStatus(ClassStatus::Null);

		return true;
	} else
	{
		AF_ERROR("unknown flag at " + std::to_string(pos));
	}

	return true;
}

bool ReaderPrivate::LoadClass32(Class* dst, ClassType* h)
{
	auto    pos  = m_stream->GetPos();
	uint8_t flag = 0;
	AF_LOAD(flag);

	if (flag == CLASS_STATUS_1)
	{
		dst->SetClassStatus(ClassStatus::NonShared);
		dst->SetId(0);

		{
			ClassType h2;
			if (h == nullptr)
			{
				h = &h2;
				AF_LOAD(h2.tag);
				AF_LOAD(h2.id);
			}
			h->status = ClassTypeStatus::TagId;
			h->parent = dst;

			dst->AddType(*h);
		}

		if (!LoadFields(dst))
		{
			return false;
		}
	} else if (flag == CLASS_STATUS_0)
	{
		dst->SetClassStatus(ClassStatus::Null);
		return true;
	} else
	{
		AF_ERROR("unknown flag at " + std::to_string(pos));
	}

	return true;
}

bool ReaderPrivate::Load(const ByteBuffer& buf)
{
	Clear();

	m_stream = new Stream(buf.data(), 0, buf.size());
	m_doc    = new DocDat();
	m_map    = new ClassHashmap();

	m_doc->SetMap(m_map);

	if (!m_doc->Load(m_stream))
	{
		SetErrorMessage(m_doc->GetErrorMessage());
		return false;
	}

	m_doc->SetClassStatus(ClassStatus::Root);
	m_doc->SetId(0);

	ClassType h;
	h.status = ClassTypeStatus::Tag;
	h.parent = m_doc;
	h.tag    = m_doc->f.type_tag;
	m_doc->AddType(h);

	return LoadFields(m_doc);
}

bool ReaderPrivate::DbgDump() const
{
	std::stringstream sout;
	JsonPrint(m_doc, sout, true, false, &m_doc->f);
	printf("%s\n", sout.str().c_str());
	fflush(stdout);
	return true;
}

Reader::Reader(): m_pimpl(new ReaderPrivate) {}

Reader::~Reader()
{
	delete m_pimpl;
}

bool Reader::Load(const ByteBuffer& buf)
{
	return m_pimpl->Load(buf);
}

bool Reader::DbgDump() const
{
	return m_pimpl->DbgDump();
}

const std::string& Reader::GetErrorMessage() const
{
	return m_pimpl->GetErrorMessage();
}

const Class* Reader::GetDoc() const
{
	return m_pimpl->GetDoc();
}

const DocFormat* Reader::GetDocFormat() const
{
	return m_pimpl->GetDocFormat();
}

} // namespace AffinityReader
