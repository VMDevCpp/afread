// Copyright (c) 2020 Vladimir Mamonov
// Licensed under the MIT license.

#include "Affinity/Json.h"

#include "Affinity/Model.h"
#include "Affinity/Utils.h"

#include <array>
#include <functional>
#include <utility>

#define AF_VISIT_B(t)                                                                                                                      \
	if (var.IsType<t>())                                                                                                                   \
	{                                                                                                                                      \
		std::invoke(std::forward<Visitor>(vis), var.GetValue<const t&>());                                                                 \
		return;                                                                                                                            \
	}

namespace AffinityReader {

static const char* g_base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                    "abcdefghijklmnopqrstuvwxyz"
                                    "0123456789+/";

static std::string base64_encode(const uint8_t* bytes_to_encode, size_t in_len)
{
	std::string ret;
	int         index = 0;
	uint8_t     char_array_3[3];
	uint8_t     char_array_4[4];

	while ((in_len--) != 0u)
	{
		char_array_3[index++] = *(bytes_to_encode++);
		if (index == 3)
		{
			char_array_4[0] = (char_array_3[0] & 0xFCu) >> 2u;
			char_array_4[1] = ((char_array_3[0] & 0x03u) << 4u) + ((char_array_3[1] & 0xF0u) >> 4u);
			char_array_4[2] = ((char_array_3[1] & 0x0Fu) << 2u) + ((char_array_3[2] & 0xC0u) >> 6u);
			char_array_4[3] = char_array_3[2] & 0x3Fu;

			for (index = 0; (index < 4); index++)
			{
				ret += g_base64_chars[char_array_4[index]];
			}
			index = 0;
		}
	}

	if (index != 0)
	{
		for (int j = index; j < 3; j++)
		{
			char_array_3[j] = '\0';
		}

		char_array_4[0] = (char_array_3[0] & 0xFCu) >> 2u;
		char_array_4[1] = ((char_array_3[0] & 0x03u) << 4u) + ((char_array_3[1] & 0xF0u) >> 4u);
		char_array_4[2] = ((char_array_3[1] & 0x0Fu) << 2u) + ((char_array_3[2] & 0xC0u) >> 6u);
		char_array_4[3] = char_array_3[2] & 0x3Fu;

		for (int j = 0; j < index + 1; j++)
		{
			ret += g_base64_chars[char_array_4[j]];
		}

		while (index++ < 3)
		{
			ret += '=';
		}
	}

	return ret;
}

template <class Visitor>
void Visit(Visitor&& vis, const Variant& var) noexcept
{
	AF_VISIT_B(SharedPtr<Class>);
	AF_VISIT_B(curve12_t);
	AF_VISIT_B(curve16_t);
	AF_VISIT_B(curve18_t);
	AF_VISIT_B(int8_t);
	AF_VISIT_B(int16_t);
	AF_VISIT_B(int32_t);
	AF_VISIT_B(int64_t);
	AF_VISIT_B(uint8_t);
	AF_VISIT_B(uint16_t);
	AF_VISIT_B(uint32_t);
	AF_VISIT_B(uint64_t);
	AF_VISIT_B(float);
	AF_VISIT_B(double);
	AF_VISIT_B(vec_f_t<2>);
	AF_VISIT_B(vec_f_t<3>);
	AF_VISIT_B(vec_f_t<4>);
	AF_VISIT_B(vec_f_t<5>);
	AF_VISIT_B(vec_f_t<6>);
	AF_VISIT_B(vec_d_t<2>);
	AF_VISIT_B(vec_d_t<3>);
	AF_VISIT_B(vec_d_t<4>);
	AF_VISIT_B(vec_d_t<5>);
	AF_VISIT_B(vec_d_t<6>);
	AF_VISIT_B(vec_i_t<2>);
	AF_VISIT_B(vec_i_t<3>);
	AF_VISIT_B(vec_i_t<4>);
	AF_VISIT_B(vec_i_t<5>);
	AF_VISIT_B(vec_i_t<6>);
	AF_VISIT_B(std::string);
	AF_VISIT_B(EnumT);
	AF_VISIT_B(FlagsT);
	AF_VISIT_B(bool);
	AF_VISIT_B(EmbeddedData);
	AF_VISIT_B(BinaryData);
	AF_VISIT_B(Color32);
	AF_VISIT_B(ColorRGBA);
	AF_VISIT_B(ColorHSLA);
	AF_VISIT_B(ColorLABA);
	AF_VISIT_B(ColorCMYK);
	AF_VISIT_B(ColorGRAY);

	AF_VISIT_B(SharedArray<SharedPtr<Class>>);
	AF_VISIT_B(SharedArray<curve12_t>);
	AF_VISIT_B(SharedArray<curve16_t>);
	AF_VISIT_B(SharedArray<curve18_t>);
	AF_VISIT_B(SharedArray<int8_t>);
	AF_VISIT_B(SharedArray<int16_t>);
	AF_VISIT_B(SharedArray<int32_t>);
	AF_VISIT_B(SharedArray<int64_t>);
	AF_VISIT_B(SharedArray<uint8_t>);
	AF_VISIT_B(SharedArray<uint16_t>);
	AF_VISIT_B(SharedArray<uint32_t>);
	AF_VISIT_B(SharedArray<uint64_t>);
	AF_VISIT_B(SharedArray<float>);
	AF_VISIT_B(SharedArray<double>);
	AF_VISIT_B(SharedArray<vec_f_t<2>>);
	AF_VISIT_B(SharedArray<vec_f_t<3>>);
	AF_VISIT_B(SharedArray<vec_f_t<4>>);
	AF_VISIT_B(SharedArray<vec_f_t<5>>);
	AF_VISIT_B(SharedArray<vec_f_t<6>>);
	AF_VISIT_B(SharedArray<vec_d_t<2>>);
	AF_VISIT_B(SharedArray<vec_d_t<3>>);
	AF_VISIT_B(SharedArray<vec_d_t<4>>);
	AF_VISIT_B(SharedArray<vec_d_t<5>>);
	AF_VISIT_B(SharedArray<vec_d_t<6>>);
	AF_VISIT_B(SharedArray<vec_i_t<2>>);
	AF_VISIT_B(SharedArray<vec_i_t<3>>);
	AF_VISIT_B(SharedArray<vec_i_t<4>>);
	AF_VISIT_B(SharedArray<vec_i_t<5>>);
	AF_VISIT_B(SharedArray<vec_i_t<6>>);
	AF_VISIT_B(SharedArray<std::string>);
	AF_VISIT_B(SharedArray<EnumT>);
	AF_VISIT_B(SharedArray<bool>);
	AF_VISIT_B(SharedArray<Color32>);
	AF_VISIT_B(SharedArray<ColorRGBA>);
	AF_VISIT_B(SharedArray<ColorHSLA>);
	AF_VISIT_B(SharedArray<ColorLABA>);
	AF_VISIT_B(SharedArray<ColorCMYK>);
	AF_VISIT_B(SharedArray<ColorGRAY>);
	//
	//	printf("invalid type\n");
	//	exit(123);
}

static void tab(std::ostream& out, int num)
{
	for (int i = 0; i < num; i++)
	{
		out << "\t";
	}
}

struct JsonPrinter
{
	JsonPrinter(std::ostream& as, int al, int asize, bool with_type, bool with_blob)
	    : s(as), l(al), size(asize), with_type(with_type), with_blob(with_blob)
	{
	}
	std::ostream& s;
	int           l;
	int           size;
	bool          with_type;
	bool          with_blob;

	[[nodiscard]] std::string T(const std::string& str) const { return (with_type ? str : ""); }
	[[nodiscard]] const char* T(const char* str) const { return (with_type ? str : ""); }

	void operator()(const SharedPtr<Class>& arg) const
	{
		if (!arg)
		{
			s << "null";
		} else
		{
			JsonPrint(&*arg, s, with_type, with_blob);
		}
	}
	void operator()(const curve12_t& arg) const
	{
		s << T(R"({ "type": "curve12_t",  "value": )") << R"({ "_dbl": )" << arg.d[0] << R"(, "_int" : [)" << static_cast<int>(arg.u[0])
		  << ", " << static_cast<int>(arg.u[1]) << ", " << static_cast<int>(arg.u[2]) << ", " << static_cast<int>(arg.u[3]) << "] }"
		  << T(" }");
	}
	void operator()(const curve16_t& arg) const
	{
		s << T(R"({ "type": "curve16_t",  "value": )") << R"({ "_dbl": )" << arg.d[0] << R"(, "_int" : [)" << static_cast<int>(arg.u[0])
		  << ", " << static_cast<int>(arg.u[1]) << "] }" << T("}");
	}
	void operator()(const curve18_t& arg) const
	{
		s << T(R"({ "type": "curve18_t",  "value": )") << R"({ "_dbl": [)" << arg.d[0] << ", " << arg.d[1] << R"(], "_int" : [)"
		  << static_cast<int>(arg.u[0]) << ", " << static_cast<int>(arg.u[1]) << "] }" << T("}");
	}
	void operator()(const int8_t& arg) const { s << T(R"({ "type": "int8_t",     "value": )") << static_cast<int>(arg) << T("}"); }
	void operator()(const int16_t& arg) const { s << T(R"({ "type": "int16_t",    "value": )") << arg << T("}"); }
	void operator()(const int32_t& arg) const { s << T(R"({ "type": "int32_t",    "value": )") << arg << T("}"); }
	void operator()(const int64_t& arg) const { s << T(R"({ "type": "int64_t",    "value": )") << arg << T("}"); }
	void operator()(const uint8_t& arg) const
	{
		s << T(R"({ "type": "uint8_t",    "value": )") << static_cast<unsigned int>(arg) << T("}");
	}
	void operator()(const uint16_t& arg) const { s << T(R"({ "type": "uint16_t",   "value": )") << arg << T("}"); }
	void operator()(const uint32_t& arg) const { s << T(R"({ "type": "uint32_t",   "value": )") << arg << T("}"); }
	void operator()(const uint64_t& arg) const { s << T(R"({ "type": "uint64_t",   "value": )") << arg << T("}"); }
	void operator()(const float& arg) const { s << T(R"({ "type": "float",      "value": )") << arg << T("}"); }
	void operator()(const double& arg) const { s << T(R"({ "type": "double",     "value": )") << arg << T("}"); }
	void operator()(const vec_f_t<2>& arg) const
	{
		s << T(R"({ "type": "vec2_f_t",   "value": )") << "[ " << arg[0] << ", " << arg[1] << " ]" << T("}");
	}
	void operator()(const vec_f_t<3>& arg) const
	{
		s << T(R"({ "type": "vec3_f_t",   "value": )") << "[ " << arg[0] << ", " << arg[1] << ", " << arg[2] << " ]" << T("}");
	}
	void operator()(const vec_f_t<4>& arg) const
	{
		s << T(R"({ "type": "vec4_f_t",   "value": )") << "[ " << arg[0] << ", " << arg[1] << ", " << arg[2] << ", " << arg[3] << " ]"
		  << T("}");
	}
	void operator()(const vec_f_t<5>& arg) const
	{
		s << T(R"({ "type": "vec5_f_t",   "value": )") << "[ " << arg[0] << ", " << arg[1] << ", " << arg[2] << ", " << arg[3] << ", "
		  << arg[4] << " ]" << T("}");
	}
	void operator()(const vec_f_t<6>& arg) const
	{
		s << T(R"({ "type": "vec6_f_t",   "value": )") << "[ " << arg[0] << ", " << arg[1] << ", " << arg[2] << ", " << arg[3] << ", "
		  << arg[4] << ", " << arg[5] << " ]" << T("}");
	}
	void operator()(const vec_d_t<2>& arg) const
	{
		s << T(R"({ "type": "vec2_d_t",   "value": )") << "[ " << arg[0] << ", " << arg[1] << " ]" << T("}");
	}
	void operator()(const vec_d_t<3>& arg) const
	{
		s << T(R"({ "type": "vec3_d_t",   "value": )") << "[ " << arg[0] << ", " << arg[1] << ", " << arg[2] << " ]" << T("}");
	}
	void operator()(const vec_d_t<4>& arg) const
	{
		s << T(R"({ "type": "vec4_d_t",   "value": )") << "[ " << arg[0] << ", " << arg[1] << ", " << arg[2] << ", " << arg[3] << " ]"
		  << T("}");
	}
	void operator()(const vec_d_t<5>& arg) const
	{
		s << T(R"({ "type": "vec5_d_t",   "value": )") << "[ " << arg[0] << ", " << arg[1] << ", " << arg[2] << ", " << arg[3] << ", "
		  << arg[4] << " ]" << T("}");
	}
	void operator()(const vec_d_t<6>& arg) const
	{
		s << T(R"({ "type": "vec6_d_t",   "value": )") << "[ " << arg[0] << ", " << arg[1] << ", " << arg[2] << ", " << arg[3] << ", "
		  << arg[4] << ", " << arg[5] << " ]" << T("}");
	}
	void operator()(const vec_i_t<2>& arg) const
	{
		s << T(R"({ "type": "vec2_i_t",   "value": )") << "[ " << arg[0] << ", " << arg[1] << " ]" << T("}");
	}
	void operator()(const vec_i_t<3>& arg) const
	{
		s << T(R"({ "type": "vec3_i_t",   "value": )") << "[ " << arg[0] << ", " << arg[1] << ", " << arg[2] << " ]" << T("}");
	}
	void operator()(const vec_i_t<4>& arg) const
	{
		s << T(R"({ "type": "vec4_i_t",   "value": )") << "[ " << arg[0] << ", " << arg[1] << ", " << arg[2] << ", " << arg[3] << " ]"
		  << T("}");
	}
	void operator()(const vec_i_t<5>& arg) const
	{
		s << T(R"({ "type": "vec5_i_t",   "value": )") << "[ " << arg[0] << ", " << arg[1] << ", " << arg[2] << ", " << arg[3] << ", "
		  << arg[4] << " ]" << T("}");
	}
	void operator()(const vec_i_t<6>& arg) const
	{
		s << T(R"({ "type": "vec6_i_t",   "value": )") << "[ " << arg[0] << ", " << arg[1] << ", " << arg[2] << ", " << arg[3] << ", "
		  << arg[4] << ", " << arg[5] << " ]" << T("}");
	}
	void operator()(const std::string& arg) const { s << T(R"({ "type": "string",     "value": )") << QuotedString(arg) << T("}"); }
	void operator()(const EnumT& arg) const
	{
		s << T(R"({ "type": "EnumT",     "value": )") << "\"" << arg.version << "." << arg.id << "\"" << T("}");
	}
	void operator()(const FlagsT& arg) const
	{
		s << T(R"({ "type": "FlagsT",     "value": )") << "\"" << arg.version << "." << arg.flags << "\"" << T("}");
	}
	void operator()(const bool& arg) const { s << T(R"({ "type": "bool",       "value": )") << (arg ? "true" : "false") << T("}"); }
	void operator()(const EmbeddedData& arg) const
	{
		s << T(R"({ "type": "EmbeddedData",       )") << T(TagToString(arg.tag)) << T(" : ") << QuotedString(arg.data) << T(" }");
	}
	void operator()(const BinaryData& arg) const
	{
		if (with_type)
		{
			s << R"({ "type": "BinaryData", )"
			  << R"("size": )" << arg.buf.size() << R"(, "base64": )";
		}
		s << "\"" << (with_blob ? base64_encode(reinterpret_cast<const uint8_t*>(arg.buf.data()), arg.buf.size()) : "") << "\"";
		s << T("}");
	}
	void operator()(const Color32& arg) const
	{
		s << T(R"({ "type": "Color32",   "value": )") << "[ " << static_cast<unsigned int>(arg.c[0]) << ", "
		  << static_cast<unsigned int>(arg.c[1]) << ", " << static_cast<unsigned int>(arg.c[2]) << ", "
		  << static_cast<unsigned int>(arg.c[3]) << " ]" << T("}");
	}
	void operator()(const ColorRGBA& arg) const
	{
		s << T(R"({ "type": "ColorRGBA",   "value": )") << "[ " << arg.c[0] << ", " << arg.c[1] << ", " << arg.c[2] << ", " << arg.c[3]
		  << " ]" << T("}");
	}
	void operator()(const ColorHSLA& arg) const
	{
		s << T(R"({ "type": "ColorHSLA",   "value": )") << "[ " << arg.c[0] << ", " << arg.c[1] << ", " << arg.c[2] << ", " << arg.c[3]
		  << " ]" << T("}");
	}
	void operator()(const ColorLABA& arg) const
	{
		s << T(R"({ "type": "ColorLABA",   "value": )") << "[ " << arg.c[0] << ", " << arg.c[1] << ", " << arg.c[2] << ", " << arg.c[3]
		  << " ]" << T("}");
	}
	void operator()(const ColorCMYK& arg) const
	{
		s << T(R"({ "type": "ColorCMYK",   "value": )") << "[ " << arg.c[0] << ", " << arg.c[1] << ", " << arg.c[2] << ", " << arg.c[3]
		  << ", " << arg.c[4] << " ]" << T("}");
	}
	void operator()(const ColorGRAY& arg) const
	{
		s << T(R"({ "type": "ColorGRAY",   "value": )") << "[ " << arg.c[0] << ", " << arg.c[1] << " ]" << T("}");
	}
	void operator()(const SharedArray<SharedPtr<Class>>& arg) const
	{
		if (size == 0)
		{
			s << "[]";
		} else
		{
			s << "[\n";
			for (int i = 0; i < size; i++)
			{
				tab(s, l + 2);
				if (!arg[i])
				{
					s << "null";
				} else
				{
					JsonPrint(&*arg[i], s, with_type, with_blob);
				}
				s << (i + 1 != size ? "," : "") << "\n";
			}
			tab(s, l + 1);
			s << "]";
		}
	}
	void operator()(const SharedArray<curve12_t>& arg) const
	{
		s << T(R"({ "type": "curve12_t[]","value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << R"({ "_dbl": )" << arg[i].d[0] << R"(, "_int" : [)" << static_cast<int>(arg[i].u[0]) << ", "
			  << static_cast<int>(arg[i].u[1]) << ", " << static_cast<int>(arg[i].u[2]) << ", " << static_cast<int>(arg[i].u[3]) << "] }"
			  << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<curve16_t>& arg) const
	{
		s << T(R"({ "type": "curve16_t[]","value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << R"({ "_dbl": )" << arg[i].d[0] << R"(, "_int" : [)" << static_cast<int>(arg[i].u[0]) << ", "
			  << static_cast<int>(arg[i].u[1]) << "] }" << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<curve18_t>& arg) const
	{
		s << T(R"({ "type": "curve18_t[]","value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << R"({ "_dbl": [ )" << arg[i].d[0] << ", " << arg[i].d[1] << R"(], "_int" : [)" << static_cast<int>(arg[i].u[0]) << ", "
			  << static_cast<int>(arg[i].u[1]) << "] }" << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<int32_t>& arg) const
	{
		s << T(R"({ "type": "int32_t[]", "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << arg[i] << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<int8_t>& arg) const
	{
		s << T(R"({ "type": "int8_t[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << static_cast<int>(arg[i]) << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<int16_t>& arg) const
	{
		s << T(R"({ "type": "int16_t[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << arg[i] << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<int64_t>& arg) const
	{
		s << T(R"({ "type": "int64_t[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << arg[i] << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<uint8_t>& arg) const
	{
		s << T(R"({ "type": "uint8_t[]",  "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << static_cast<unsigned int>(arg[i]) << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<uint16_t>& arg) const
	{
		s << T(R"({ "type": "uint16_t[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << arg[i] << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<uint32_t>& arg) const
	{
		s << T(R"({ "type": "uint32_t[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << arg[i] << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<uint64_t>& arg) const
	{
		s << T(R"({ "type": "uint64_t[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << arg[i] << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<float>& arg) const
	{
		s << T(R"({ "type": "float[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << arg[i] << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<double>& arg) const
	{
		s << T(R"({ "type": "double[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << arg[i] << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<vec_f_t<2>>& arg) const
	{
		s << T(R"({ "type": "vec2_f_t[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << "[" << arg[i][0] << ", " << arg[i][1] << "]" << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<vec_f_t<3>>& arg) const
	{
		s << T(R"({ "type": "vec3_f_t[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << "[" << arg[i][0] << ", " << arg[i][1] << ", " << arg[i][2] << "]" << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<vec_f_t<4>>& arg) const
	{
		s << T(R"({ "type": "vec4_f_t[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << "[" << arg[i][0] << ", " << arg[i][1] << ", " << arg[i][2] << ", " << arg[i][3] << "]" << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<vec_f_t<5>>& arg) const
	{
		s << T(R"({ "type": "vec5_f_t[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << "[" << arg[i][0] << ", " << arg[i][1] << ", " << arg[i][2] << ", " << arg[i][3] << ", " << arg[i][4] << "]"
			  << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<vec_f_t<6>>& arg) const
	{
		s << T(R"({ "type": "vec6_f_t[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << "[" << arg[i][0] << ", " << arg[i][1] << ", " << arg[i][2] << ", " << arg[i][3] << ", " << arg[i][4] << ", " << arg[i][5]
			  << "]" << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<vec_d_t<2>>& arg) const
	{
		s << T(R"({ "type": "vec2_d_t[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << "[" << arg[i][0] << ", " << arg[i][1] << "]" << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<vec_d_t<3>>& arg) const
	{
		s << T(R"({ "type": "vec3_d_t[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << "[" << arg[i][0] << ", " << arg[i][1] << ", " << arg[i][2] << "]" << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<vec_d_t<4>>& arg) const
	{
		s << T(R"({ "type": "vec4_d_t[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << "[" << arg[i][0] << ", " << arg[i][1] << ", " << arg[i][2] << ", " << arg[i][3] << "]" << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<vec_d_t<5>>& arg) const
	{
		s << T(R"({ "type": "vec5_d_t[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << "[" << arg[i][0] << ", " << arg[i][1] << ", " << arg[i][2] << ", " << arg[i][3] << ", " << arg[i][4] << "]"
			  << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<vec_d_t<6>>& arg) const
	{
		s << T(R"({ "type": "vec6_d_t[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << "[" << arg[i][0] << ", " << arg[i][1] << ", " << arg[i][2] << ", " << arg[i][3] << ", " << arg[i][4] << ", " << arg[i][5]
			  << "]" << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<vec_i_t<2>>& arg) const
	{
		s << T(R"({ "type": "vec2_i_t[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << "[" << arg[i][0] << ", " << arg[i][1] << "]" << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<vec_i_t<3>>& arg) const
	{
		s << T(R"({ "type": "vec3_i_t[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << "[" << arg[i][0] << ", " << arg[i][1] << ", " << arg[i][2] << "]" << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<vec_i_t<4>>& arg) const
	{
		s << T(R"({ "type": "vec4_i_t[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << "[" << arg[i][0] << ", " << arg[i][1] << ", " << arg[i][2] << ", " << arg[i][3] << "]" << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<vec_i_t<5>>& arg) const
	{
		s << T(R"({ "type": "vec5_i_t[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << "[" << arg[i][0] << ", " << arg[i][1] << ", " << arg[i][2] << ", " << arg[i][3] << ", " << arg[i][4] << "]"
			  << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<vec_i_t<6>>& arg) const
	{
		s << T(R"({ "type": "vec6_i_t[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << "[" << arg[i][0] << ", " << arg[i][1] << ", " << arg[i][2] << ", " << arg[i][3] << ", " << arg[i][4] << ", " << arg[i][5]
			  << "]" << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<std::string>& arg) const
	{
		s << T(R"({ "type": "string[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << QuotedString(arg[i]) << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<EnumT>& arg) const
	{
		s << T(R"({ "type": "EnumT[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << "\"" << arg[i].version << "." << arg[i].id << "\"" << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<bool>& arg) const
	{
		s << T(R"({ "type": "bool[]",     "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << (arg[i] ? "true" : "false") << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<Color32>& arg) const
	{
		s << T(R"({ "type": "Color32[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << "[" << static_cast<unsigned int>(arg[i].c[0]) << ", " << static_cast<unsigned int>(arg[i].c[1]) << ", "
			  << static_cast<unsigned int>(arg[i].c[2]) << ", " << static_cast<unsigned int>(arg[i].c[3]) << "]"
			  << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<ColorRGBA>& arg) const
	{
		s << T(R"({ "type": "ColorRGBA[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << "[" << arg[i].c[0] << ", " << arg[i].c[1] << ", " << arg[i].c[2] << ", " << arg[i].c[3] << "]"
			  << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<ColorHSLA>& arg) const
	{
		s << T(R"({ "type": "ColorHSLA[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << "[" << arg[i].c[0] << ", " << arg[i].c[1] << ", " << arg[i].c[2] << ", " << arg[i].c[3] << "]"
			  << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<ColorLABA>& arg) const
	{
		s << T(R"({ "type": "ColorLABA[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << "[" << arg[i].c[0] << ", " << arg[i].c[1] << ", " << arg[i].c[2] << ", " << arg[i].c[3] << "]"
			  << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<ColorCMYK>& arg) const
	{
		s << T(R"({ "type": "ColorCMYK[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << "[" << arg[i].c[0] << ", " << arg[i].c[1] << ", " << arg[i].c[2] << ", " << arg[i].c[3] << ", " << arg[i].c[4] << "]"
			  << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
	void operator()(const SharedArray<ColorGRAY>& arg) const
	{
		s << T(R"({ "type": "ColorGRAY[]",   "value": )") << "[";
		for (int i = 0; i < size; i++)
		{
			s << "[" << arg[i].c[0] << ", " << arg[i].c[1] << "]" << (i + 1 != size ? ", " : "");
		}
		s << "]" << T("}");
	}
};

inline std::string ClassStatusToString(ClassStatus class_status)
{
	switch (class_status)
	{
		case ClassStatus::Invalid: return QuotedString("Invalid");
		case ClassStatus::Root: return QuotedString("Root");
		case ClassStatus::Link: return QuotedString("Link");
		case ClassStatus::Null: return QuotedString("Null");
		case ClassStatus::Shared: return QuotedString("Shared");
		case ClassStatus::NonShared: return QuotedString("NonShared");
	}
	return QuotedString("");
}

void JsonPrint(const Class* c, std::ostream& s, bool with_type, bool with_blob, const DocFormat* f)
{
	int  l              = c->GetLevel();
	auto class_status   = c->GetClassStatus();
	auto m_fields       = c->GetFields();
	bool m_fields_empty = m_fields.empty();

	if (m_fields_empty && class_status == ClassStatus::Null)
	{
		s << "{}";
	} else
	{
		s << "{\n";
		if (f != nullptr && class_status == ClassStatus::Root)
		{
			tab(s, l + 1);
			s << "\"file_tag\": " << TagToString(f->file_tag) << ",\n";
			tab(s, l + 1);
			s << "\"file_ver\": " << f->file_ver << ",\n";
			tab(s, l + 1);
			s << "\"type_tag\": " << TagToString(f->type_tag) << ",\n";
			tab(s, l + 1);
			s << "\"type_ver\": " << f->type_ver << ",\n";
			tab(s, l + 1);
			s << "\"version\":  " << f->version << (!m_fields_empty ? "," : "") << "\n";
		}

		if (class_status != ClassStatus::Null)
		{
			tab(s, l + 1);
			s << "\"status\": " << ClassStatusToString(class_status) << ",\n";
			if (class_status == ClassStatus::Shared || class_status == ClassStatus::Link)
			{
				tab(s, l + 1);
				s << "\"id\":     " << c->GetId() << ","
				  << "\n";
			}
			tab(s, l + 1);
			s << "\"type\": " << TagToString(c->GetType()) << (!m_fields_empty ? "," : "") << "\n";
		}

		size_t index = 0;
		for (auto& f: m_fields)
		{
			if (f.no_tag)
			{
				tab(s, l + 1);
				s << "\"_" << index << "\" : ";
			} else
			{
				tab(s, l + 1);
				s << (TagToString(f.tag)) << " : ";
			}

			Visit(JsonPrinter(s, l, f.count, with_type, with_blob), f.value);
			s << (++index != m_fields.size() ? "," : "") << "\n";
		}

		tab(s, l);
		s << "}";
	}
}

} // namespace AffinityReader
