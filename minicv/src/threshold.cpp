#include <cassert>

#include "threshold.h"

//gray -> binaryzation
API_DESC bool threshold(const unsigned char* srcData, const int width, const int height, 
	const int threshold, const unsigned char low, const unsigned char high, unsigned char* dstData)
{
	assert(!(!srcData || !dstData || width <= 0 || height <= 0 || threshold <= 0 || threshold >= 255));
	if (!srcData || !dstData || width <= 0 || height <= 0 || threshold<=0 || threshold>=255)
	{
		return false;
	}
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			const int index = y*width + x;
			const unsigned char gray = srcData[index];			
			dstData[index] = (gray > threshold ? high : low);
		}
	}
	return true;
}