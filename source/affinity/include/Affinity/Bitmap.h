// Copyright (c) 2020-2021 Vladimir Mamonov
// Licensed under the MIT license.

#ifndef AFFINITY_BITMAP_H_
#define AFFINITY_BITMAP_H_

#include "Affinity/Utils.h"

namespace AffinityReader {

class Archive;

namespace CppModel {
struct Rstr;
} // namespace CppModel

enum class BitmapFormat
{
	Unknown,
	RGB8,
	RGB16,
	RGB32,
	Gray8,
	Gray16,
	CMYK8,
	LAB16
};

class Bitmap
{
public:
	Bitmap(const CppModel::Rstr* layer, const Archive* archive);
	virtual ~Bitmap();

	AF_NO_COPY(Bitmap);

	[[nodiscard]] int          GetChannelsNum() const { return m_channels_num; }
	[[nodiscard]] BitmapFormat GetFormat() const { return m_format; }
	[[nodiscard]] int          GetHeight() const { return m_height; }
	[[nodiscard]] int          GetPixelSize() const { return m_pixel_size; }
	[[nodiscard]] uint8_t*     GetPixels(int channel) const { return (channel >= m_channels_num ? nullptr : m_pixels[channel]); }
	[[nodiscard]] int          GetWidth() const { return m_width; }
	[[nodiscard]] int          GetPitch() const { return m_pitch; }

	// Every color channel in range [0.0f, 1.0f]
	void GetPixelRgb(int px, int py, float* r, float* g, float* b, float* alpha) const;

	// Every color channel in range [0.0f, 1.0f]
	void GetPixelGray(int px, int py, float* gray, float* alpha) const;

	// Every color channel in range [0.0f, 1.0f]
	void GetPixelCmyk(int px, int py, float* c, float* m, float* y, float* k, float* alpha) const;

	// Range: L: [0.0f, 100.0f], A and B: [-128.0f, 127.0f], alpha: [0.0f, 1.0f]
	void GetPixelLab(int px, int py, float* l, float* a, float* b, float* alpha) const;

private:
	uint8_t**    m_pixels       = {nullptr};
	int          m_channels_num = {0};
	int          m_pixel_size   = {0};
	int          m_width        = {0};
	int          m_height       = {0};
	int          m_pitch        = {0};
	BitmapFormat m_format       = {BitmapFormat::Unknown};
};

} // namespace AffinityReader

#endif /* AFFINITY_BITMAP_H_ */
