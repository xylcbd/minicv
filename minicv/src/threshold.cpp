#include <cassert>

#include "threshold.h"

//gray -> binaryzation
API_DESC bool threshold(const unsigned char* srcData, const int width, const int height, 
	const unsigned char thrshold, const unsigned char low, const unsigned char high, unsigned char* dstData)
{
	assert(!(!srcData || !dstData || width <= 0 || height <= 0 || thrshold <= 0 || thrshold >= 255));
	if (!srcData || !dstData || width <= 0 || height <= 0 || thrshold <= 0 || thrshold >= 255)
	{
		return false;
	}
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			const int index = y*width + x;
			const unsigned char gray = srcData[index];			
			dstData[index] = (gray > thrshold ? high : low);
		}
	}
	return true;
}

//ostu
static unsigned char ostu(const unsigned char* srcData, const int width, const int height)
{
	assert(srcData && width>0 && height>0);
	if (!(srcData && width > 0 && height > 0))
	{
		return 0;
	}

	int pixelCount[256] = { 0 };
	float pixelPro[256] = { 0.0f };
	for (int i = 0; i < 256; i++)
	{
		pixelCount[i] = 0;
		pixelPro[i] = 0;
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			pixelCount[srcData[i * width + j]]++;
		}
	}

	const auto pixelSum = width * height;
	for (int i = 0; i < 256; i++)
	{
		pixelPro[i] = (float)(pixelCount[i]) / (float)(pixelSum);
	}

	unsigned char thrshold = 0;
	float deltaMax = 0;
	for (int i = 0; i < 256; i++)
	{
		float w0 = 0.0f, w1 = 0.0f, u0tmp = 0.0f, u1tmp = 0.0f;
		for (int j = 0; j < 256; j++)
		{
			if (j <= i) 
			{
				w0 += pixelPro[j];
				u0tmp += j * pixelPro[j];
			}
			else
			{
				w1 += pixelPro[j];
				u1tmp += j * pixelPro[j];
			}
		}

		const auto u0 = u0tmp / w0;
		const auto u1 = u1tmp / w1;
		const auto u = u0tmp + u1tmp;
		const auto deltaTmp = w0 * (u0 - u)*(u0 - u) + w1 * (u1 - u)*(u1 - u);
		if (deltaTmp > deltaMax)
		{
			deltaMax = deltaTmp;
			thrshold = static_cast<unsigned char>(i);
		}
	}
	return thrshold;
}
//gray -> binaryzation
API_DESC bool ostuThreshold(const unsigned char* srcData, const int width, const int height,
	const unsigned char low, const unsigned char high, unsigned char* dstData)
{
	const auto thrshold = ostu(srcData, width, height);
	return threshold(srcData, width, height, thrshold, low, high, dstData);
}