// Copyright (c) 2020 Vladimir Mamonov
// Licensed under the MIT license.

// This example is not fully compilable
// You need to sub-class AffinityReader::Driver and provide you own implementation of driver

#include "Affinity/Affinity.h"
#include "Affinity/CppStructs.h"

class Driver: public AffinityReader::Driver
{
	// provide you own implementation of base class api
};

namespace CppModel = AffinityReader::CppModel;

void tab(int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("  ");
	}
}

void dump_layer(CppModel::BaseLayer* layer, int level)
{
	tab(level);
	switch (layer->base_type)
	{
		case CppModel::BaseLayer::Type::ShpN: printf("%s (Shape)\n", static_cast<CppModel::ShpN*>(layer)->Desc.c_str()); break;
		case CppModel::BaseLayer::Type::Grup: printf("%s (Group)\n", static_cast<CppModel::Grup*>(layer)->Desc.c_str()); break;
		case CppModel::BaseLayer::Type::PCrv: printf("%s (Curve)\n", static_cast<CppModel::PCrv*>(layer)->Desc.c_str()); break;
		default: printf("%s (Some layer)\n", layer->Desc.c_str());
	}

	for (auto* chld: layer->Chld)
	{
		dump_layer(chld, level + 1);
	}
}

int main(int argc, char** argv)
{
	Driver driver;

	AffinityReader::Affinity af;

	if (!af.Load("c:/my_files/my.afdesign", &driver))
	{
		printf("Error: %s\n", af.GetErrMsg().c_str());
		return 1;
	}

	const CppModel::Pers* doc = af.GetPers();

	printf("Document description: %s\n", doc->DocR->Desc.c_str());

	for (CppModel::Sprd* chld: doc->DocR->Chld)
	{
		dump_layer(chld, 0);
	}

	return 0;
}
