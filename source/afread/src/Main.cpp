#include "Affinity/Affinity.h"
#include "Affinity/Json.h"
#include "Affinity/Reader.h"
#include "WindowsDriver.h"
#include "cxxopts.hpp"

#include <fstream>

namespace afread {

bool dump_json(const std::string& in, const std::string& out, bool base64, bool notype)
{
	WindowsDriver driver;

	AffinityReader::Affinity af;

	if (!af.Load(in, &driver))
	{
		std::cout << af.GetErrMsg() << std::endl;
		return false;
	}

	std::ofstream file;
	file.open(out.c_str(), std::fstream::out);
	AffinityReader::JsonPrint(af.GetReader()->GetDoc(), file, !notype, base64, af.GetReader()->GetDocFormat());
	file.close();

	return true;
}

} // namespace afread

int main(int argc, char* argv[])
{
	cxxopts::Options options("afread", "Tool to read and dump affinity files");

	bool base64 = false;
	bool notype = false;

	// clang-format off
	options.add_options()("h,help", "Print usage information and exit.")
			("i,input", "Input file (.afdesign|.afphoto|.afpub|.aftemplate|.dat|.propcol)", cxxopts::value<std::string>())
			("j,json", "Output file", cxxopts::value<std::string>())
			("blob", "Dump binary data to json (as base64 strings)", cxxopts::value<bool>(base64))
			("notype", "Don't dump type information", cxxopts::value<bool>(notype));
	// clang-format on

	std::string input_file;
	std::string json_out;

	try
	{
		auto result = options.parse(argc, argv);

		if (result.count("help"))
		{
			std::cout << options.help() << std::endl;
			return 0;
		} else
		{
			if (result.count("input"))
			{
				input_file = result["input"].as<std::string>();
			}
			if (result.count("json"))
			{
				json_out = result["json"].as<std::string>();
			}
		}
	} catch (const cxxopts::OptionException& e)
	{
		std::cout << "Error parsing options: " << e.what() << std::endl << std::endl;
		std::cout << options.help() << std::endl;
		return 1;
	}

	if (input_file.empty())
	{
		std::cout << "Input file is not specified" << std::endl << std::endl;
		std::cout << "Run 'afread --help' for more information." << std::endl;
		return 2;
	}

	if (json_out.empty())
	{
		json_out = input_file.substr(0, input_file.find_last_of('.')) + ".json";
	}

	if (!afread::dump_json(input_file, json_out, base64, notype))
	{
		return 3;
	}

	return 0;
}
