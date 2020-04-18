// Copyright (c) 2020 Vladimir Mamonov
// Licensed under the MIT license.

#include "Affinity/Model.h"

#include <memory>

namespace AffinityReader {

#define AF_ERROR(msg)                                                                                                                      \
	*err_msg = std::string(msg) + " in " + std::string(__FILE__) + ":" + std::to_string(__LINE__) + "\n";                                  \
	return false;

bool ConvertClass_PCvD_Data(Class* dst, std::string* err_msg)
{
	auto& fields = dst->GetFields();

	if (fields.size() <= 2 || !(fields[0].value.IsType<uint8_t>() && fields[1].value.IsType<uint32_t>()))
	{
		AF_ERROR("invalid class");
	}

	fields[0].SetTag("byte"_tag);
	fields[1].SetTag("size"_tag);

	uint32_t count = fields[1].value.GetValue<uint32_t>();

	if (fields.size() != count * 2 + 2)
	{
		AF_ERROR("invalid class");
	}

	SharedArray<SharedPtr<Class>> clss = SharedArray<SharedPtr<Class>>(count != 0U ? new SharedPtr<Class>[count] : nullptr, count);

	for (uint32_t i = 0; i < count; i++)
	{
		auto& f1 = fields[i * 2 + 2];
		auto& f2 = fields[i * 2 + 2 + 1];

		if (!(f1.value.IsType<bool>() && f2.value.IsType<SharedArray<curve18_t>>()))
		{
			AF_ERROR("invalid class");
		}

		auto* cls = new Class();
		clss[i]   = SharedPtr<Class>(cls);

		cls->SetLevel(dst->GetLevel() + 2);
		cls->SetClassStatus(ClassStatus::NonShared);
		cls->SetType("__C1"_tag);
		f1.parent = cls;
		f1.SetTag("bool"_tag);
		f2.parent = cls;
		f2.SetTag("crvs"_tag);
		cls->GetFields().Add(f1);
		cls->GetFields().Add(f2);
	}

	fields.erase(fields.begin() + 2, fields.end());
	Field f;
	f.count = static_cast<int>(count);
	f.SetTag("list"_tag);
	f.parent = dst;
	f.value  = clss;
	fields.Add(f);

	dst->SetType("_CB1"_tag);

	return true;
}

bool ConvertClass_PCvD_CnrD(Class* dst, std::string* err_msg)
{
	auto& fields = dst->GetFields();

	if (fields.size() <= 1 || !(fields[0].value.IsType<uint8_t>()))
	{
		AF_ERROR("invalid class");
	}

	size_t count = (fields.size() - 1) / 3;

	if (fields.size() != count * 3 + 1)
	{
		AF_ERROR("invalid class");
	}

	fields[0].SetTag("byte"_tag);

	SharedArray<SharedPtr<Class>> clss = SharedArray<SharedPtr<Class>>(count != 0U ? new SharedPtr<Class>[count] : nullptr, count);

	for (int i = 0; i < static_cast<int>(count); i++)
	{
		auto& f1 = fields[i * 3 + 1 + 0];
		auto& f2 = fields[i * 3 + 1 + 1];
		auto& f3 = fields[i * 3 + 1 + 2];

		if (!(f1.value.IsType<SharedArray<int32_t>>() && f2.value.IsType<SharedArray<double>>() && f3.value.IsType<SharedArray<uint8_t>>()))
		{
			AF_ERROR("invalid class");
		}

		auto* cls = new Class();
		clss[i]   = SharedPtr<Class>(cls);

		cls->SetLevel(dst->GetLevel() + 2);
		cls->SetClassStatus(ClassStatus::NonShared);
		cls->SetType("__C2"_tag);
		f1.parent = cls;
		f1.SetTag("ints"_tag);
		f2.parent = cls;
		f2.SetTag("dbls"_tag);
		f3.parent = cls;
		f3.SetTag("byts"_tag);
		cls->GetFields().Add(f1);
		cls->GetFields().Add(f2);
		cls->GetFields().Add(f3);
	}

	fields.erase(fields.begin() + 1, fields.end());
	Field f;
	f.count = static_cast<int>(count);
	f.SetTag("list"_tag);
	f.parent = dst;
	f.value  = clss;
	fields.Add(f);

	dst->SetType("_CB2"_tag);

	return true;
}

bool ConvertClass_CrvD_Data(Class* dst, std::string* err_msg)
{
	auto& fields = dst->GetFields();

	if (fields.size() != 3 ||
	    !(fields[0].value.IsType<uint8_t>() && fields[1].value.IsType<bool>() && fields[2].value.IsType<SharedArray<curve18_t>>()))
	{
		AF_ERROR("invalid class");
	}

	dst->SetType("_CB3"_tag);

	fields[0].SetTag("byte"_tag);
	fields[1].SetTag("bool"_tag);
	fields[2].SetTag("crvs"_tag);

	return true;
}

bool ConvertClass_Undo_On(Class* dst, std::string* err_msg)
{
	auto& fields = dst->GetFields();

	if (fields.size() != 5 ||
	    !(fields[0].value.IsType<uint8_t>() && fields[1].value.IsType<uint32_t>() && fields[2].value.IsType<vec_d_t<2>>() &&
	      fields[3].value.IsType<vec_i_t<2>>() && fields[4].value.IsType<EnumT>()))
	{
		AF_ERROR("invalid class");
	}

	dst->SetType("_CB4"_tag);

	fields[0].SetTag("byte"_tag);
	fields[1].SetTag("int "_tag);
	fields[2].SetTag("vecd"_tag);
	fields[3].SetTag("veci"_tag);
	fields[4].SetTag("enum"_tag);

	return true;
}

bool ConvertClass_Undo_Off(Class* dst, std::string* err_msg)
{
	auto& fields = dst->GetFields();

	if (fields.size() != 6 ||
	    !(fields[0].value.IsType<uint8_t>() && fields[1].value.IsType<uint32_t>() && fields[2].value.IsType<vec_d_t<2>>() &&
	      fields[3].value.IsType<vec_i_t<2>>() && fields[4].value.IsType<vec_d_t<2>>() && fields[5].value.IsType<vec_i_t<2>>()))
	{
		AF_ERROR("invalid class");
	}

	dst->SetType("_CB5"_tag);

	fields[0].SetTag("byte"_tag);
	fields[1].SetTag("int "_tag);
	fields[2].SetTag("vcd1"_tag);
	fields[3].SetTag("vci1"_tag);
	fields[4].SetTag("vcd2"_tag);
	fields[5].SetTag("vci2"_tag);

	return true;
}

void FieldsList::Add(const Field& f)
{
	if (!f.no_tag && Find(f.tag) != nullptr)
	{
		Field f2(f);
		f2.tag++;
		Add(f2);
	} else
	{
		std::vector<Field>::push_back(f);
	}
}

Field* FieldsList::Find(uint32_t tag)
{
	for (auto& f: *this)
	{
		if (f.tag == tag)
		{
			return &f;
		}
	}

	return nullptr;
}

const Field* FieldsList::Find(uint32_t tag) const
{
	for (const auto& f: *this)
	{
		if (f.tag == tag)
		{
			return &f;
		}
	}

	return nullptr;
}

uint32_t Class::GetType() const
{
	if (m_types.empty())
	{
		if (m_class_status == ClassStatus::Link && m_map != nullptr)
		{
			const auto* f = m_map->Find(m_id);
			if (f != nullptr)
			{
				return f->GetType();
			}
		}
		return 0;
	}
	if (m_types.at(0).tag == "ICCP"_tag && m_class_status == ClassStatus::NonShared)
	{
		return "ICC "_tag;
	}
	return m_types.at(0).tag;
}

void Class::SetType(uint32_t tag)
{
	ClassType h;
	h.parent = this;
	h.id     = 0;
	h.tag    = tag;
	h.status = ClassTypeStatus::TagId;

	m_types.clear();
	m_types.push_back(h);
}

const Class* ClassHashmap::Find(uint32_t id)
{
	auto f = find(id);
	if (f != end())
	{
		return f->second;
	}
	return nullptr;
}

bool AffinityReader::ClassConverter::Convert30(Class* dst, uint32_t parent_tag, uint32_t field_tag, std::string* err_msg)
{
	if (parent_tag == "PCvD"_tag && field_tag == "Data"_tag)
	{
		return ConvertClass_PCvD_Data(dst, err_msg);
	}

	if (parent_tag == "PCvD"_tag && field_tag == "CnrD"_tag)
	{
		return ConvertClass_PCvD_CnrD(dst, err_msg);
	}

	if (parent_tag == "CrvD"_tag && field_tag == "Data"_tag)
	{
		return ConvertClass_CrvD_Data(dst, err_msg);
	}

	if (parent_tag == "Undo"_tag && field_tag == "On  "_tag)
	{
		return ConvertClass_Undo_On(dst, err_msg);
	}

	if (parent_tag == "Undo"_tag && field_tag == "Off "_tag)
	{
		return ConvertClass_Undo_Off(dst, err_msg);
	}

	AF_ERROR("unknown tags: " + TagToString(parent_tag) + ", " + TagToString(field_tag));
}

} // namespace AffinityReader
