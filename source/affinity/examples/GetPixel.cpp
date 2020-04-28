// Copyright (c) 2020 Vladimir Mamonov
// Licensed under the MIT license.

// This example is not fully compilable
// You need to sub-class AffinityReader::Driver and provide you own implementation of driver

#include "Affinity/Affinity.h"
#include "Affinity/Bitmap.h"
#include "Affinity/CppStructs.h"

class Driver: public AffinityReader::Driver
{
	// provide you own implementation of base class api
};

namespace CppModel = AffinityReader::CppModel;

void FindLayers(CppModel::BaseLayer* layer, CppModel::BaseLayer::Type type, std::vector<CppModel::BaseLayer*>* out)
{
	if (layer->base_type == type)
	{
		out->push_back(layer);
	}

	for (auto* chld: layer->Chld)
	{
		FindLayers(chld, type, out);
	}
}

void ReadPixels(const AffinityReader::Bitmap& bmp)
{
	switch (bmp.GetFormat())
	{
		case AffinityReader::BitmapFormat::RGB8:
		case AffinityReader::BitmapFormat::RGB16:
		case AffinityReader::BitmapFormat::RGB32:
		{
			for (int y = 0; y < bmp.GetHeight(); y++)
			{
				for (int x = 0; x < bmp.GetWidth(); x++)
				{
					float red, green, blue, alpha;

					bmp.GetPixelRgb(x, y, &red, &green, &blue, &alpha);

					// Do something amazing with pixel at [x,y]
					// ....
				}
			}
			break;
		}
		case AffinityReader::BitmapFormat::Gray8:
		case AffinityReader::BitmapFormat::Gray16:
		{
			for (int y = 0; y < bmp.GetHeight(); y++)
			{
				for (int x = 0; x < bmp.GetWidth(); x++)
				{
					float gray, alpha;

					bmp.GetPixelGray(x, y, &gray, &alpha);

					// Do something amazing with pixel at [x,y]
					// ....
				}
			}
			break;
		}
		case AffinityReader::BitmapFormat::CMYK8:
		{
			for (int y = 0; y < bmp.GetHeight(); y++)
			{
				for (int x = 0; x < bmp.GetWidth(); x++)
				{
					float c, m, y, k, alpha;
					bmp.GetPixelCmyk(x, y, &c, &m, &y, &k, &alpha);

					// Do something amazing with pixel at [x,y]
					// ....
				}
			}
			break;
		}
		case AffinityReader::BitmapFormat::LAB16:
		{
			for (int y = 0; y < bmp.GetHeight(); y++)
			{
				for (int x = 0; x < bmp.GetWidth(); x++)
				{
					float L, A, B, alpha;
					bmp.GetPixelLab(x, y, &L, &A, &B, &alpha);

					// Do something amazing with pixel at [x,y]
					// ....
				}
			}
			break;
		}
		default: printf("Unknown bitmap format\n"); break;
	}
}

int main(int argc, char** argv)
{
	Driver driver;

	AffinityReader::Affinity af;

	if (!af.Load("c:/my_files/my.afphoto", &driver))
	{
		printf("Error: %s\n", af.GetErrMsg().c_str());
		return 1;
	}

	const CppModel::Pers* doc = af.GetPers();

	printf("Document description: %s\n", doc->DocR->Desc.c_str());

	std::vector<CppModel::BaseLayer*> layers;

	// Find all pixel layers
	for (CppModel::Sprd* chld: doc->DocR->Chld)
	{
		FindLayers(chld, CppModel::BaseLayer::Type::Rstr, &layers);
	}

	// Cycle through pixel layers
	for (auto* l: layers)
	{
		auto* rstr = static_cast<CppModel::Rstr*>(l);

		printf("Layer description: %s\n", rstr->Desc.c_str());

		// Convert layer to image
		AffinityReader::Bitmap bmp(rstr, af.GetArchive());

		// Process pixels in image
		ReadPixels(bmp);
	}

	return 0;
}
