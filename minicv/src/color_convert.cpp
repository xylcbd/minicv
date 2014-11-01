#include <cassert>
#include "color_convert.h"

//rgb -> gray
API_DESC bool rgb24ToGray(const unsigned char* srcData, const int width, const int height, unsigned char* dstData)
{
	assert(!(!srcData || !dstData || width <= 0 || height <= 0));
	if (!srcData || !dstData || width<=0 ||height<=0)
	{
		return false;
	}
	//GRAY = (R * 19595 + G * 38469 + B * 7472) >> 16
	const int srcPixelWidth = 3;
	for (int y = 0; y < height;y++)
	{
		for (int x = 0; x < width;x++)
		{
			const int index = y*width + x;
			const unsigned char* srcPixel = srcData + (index * srcPixelWidth);
			const unsigned char r = srcPixel[0];
			const unsigned char g = srcPixel[1];
			const unsigned char b = srcPixel[2];
			const unsigned char gray = static_cast<unsigned char>((r * 19595 + g * 38469 + b * 7472) >> 16);
			dstData[index] = gray;
		}
	}
	return true;
}

//rgba -> gray
API_DESC bool rgba32ToGray(const unsigned char* srcData, const int width, const int height, unsigned char* dstData)
{
	assert(!(!srcData || !dstData || width <= 0 || height <= 0));
	if (!srcData || !dstData || width <= 0 || height <= 0)
	{
		return false;
	}
	//GRAY = (R * 19595 + G * 38469 + B * 7472) >> 16
	const int srcPixelWidth = 4;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			const int index = y*width + x;
			const unsigned char* srcPixel = srcData + (index * srcPixelWidth);
			const unsigned char r = srcPixel[0];
			const unsigned char g = srcPixel[1];
			const unsigned char b = srcPixel[2];
			//const unsigned char a = srcPixel[3];
			const unsigned char gray = static_cast<unsigned char>((r * 19595 + g * 38469 + b * 7472) >> 16);
			dstData[index] = gray;
		}
	}
	return true;
}

//argb -> gray
API_DESC bool argb32ToGray(const unsigned char* srcData, const int width, const int height, unsigned char* dstData)
{
	assert(!(!srcData || !dstData || width <= 0 || height <= 0));
	if (!srcData || !dstData || width <= 0 || height <= 0)
	{
		return false;
	}
	//GRAY = (R * 19595 + G * 38469 + B * 7472) >> 16
	const int srcPixelWidth = 4;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			const int index = y*width + x;
			const unsigned char* srcPixel = srcData + (index * srcPixelWidth);
			//const unsigned char a = srcPixel[0];
			const unsigned char r = srcPixel[1];
			const unsigned char g = srcPixel[2];
			const unsigned char b = srcPixel[3];
			const unsigned char gray = static_cast<unsigned char>((r * 19595 + g * 38469 + b * 7472) >> 16);
			dstData[index] = gray;
		}
	}
	return true;
}