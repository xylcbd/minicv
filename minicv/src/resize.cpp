#include <cassert>
#include <cstring>
#include <algorithm>
#include "resize.h"

API_DESC bool resize(const unsigned char* srcData, const int srcWidth, const int srcHeight, 
	const int pixelSize, const RESIZE_METHOD resizeMethod,
	unsigned char* dstData, const int dstWidth, const int dstHeight)
{
	assert(!(!srcData || !dstData || srcWidth <= 0 || srcHeight <= 0 || pixelSize <=0 || dstWidth <= 0 || dstHeight <= 0));
	if (!srcData || !dstData || srcWidth <= 0 || srcHeight <= 0 || pixelSize <= 0 || dstWidth <= 0 || dstHeight <= 0)
	{
		return false;
	}
	if (srcWidth == dstWidth && srcHeight == dstWidth)
	{
		memcpy(dstData, srcData, srcWidth*srcHeight*pixelSize);
	}
	const auto resizeRateW = static_cast<double>(srcWidth) / static_cast<double>(dstWidth);
	const auto resizeRateH = static_cast<double>(srcHeight) / static_cast<double>(dstHeight);

	if (resizeMethod == RESIZE_METHOD::RESIZE_NEAREST)
	{
		for (int dstY = 0; dstY < dstHeight; dstY++)
		{
			const auto srcY = static_cast<int>(resizeRateH * dstY + 0.5);
			for (int dstX = 0; dstX < dstWidth; dstX++)
			{
				const auto srcX = static_cast<int>(resizeRateW * dstX + 0.5);
				const auto srcIndex = srcY*srcWidth + srcX;
				const auto dstIndex = dstY*dstWidth + dstX;
				memcpy(dstData + dstIndex*pixelSize, srcData + srcIndex*pixelSize, pixelSize);
			}
		}
	}
	else if (resizeMethod == RESIZE_METHOD::RESIZE_DLEARNER)
	{
		for (int dstY = 0; dstY < dstHeight; dstY++)
		{
			const auto srcUpY = static_cast<int>(resizeRateH * dstY);
			const auto srcDownY = std::min(srcUpY + 1, srcHeight - 1);
			const auto u = static_cast<float>(resizeRateH * dstY - srcUpY);
			for (int dstX = 0; dstX < dstWidth; dstX++)
			{
				const auto srcLeftX = static_cast<int>(resizeRateW * dstX);
				const auto srcRightX = std::min(srcLeftX + 1, srcWidth - 1);
				const auto v = static_cast<float>(resizeRateW * dstX - srcLeftX);

				//f(i+u,j+v) = (1-u)(1-v)f(i,j) + (1-u)vf(i,j+1) + u(1-v)f(i+1,j) + uvf(i+1,j+1) 
				for (int k = 0; k < pixelSize; k++)
				{
					const auto luPixelPart = (1 - u)*(1 - v) * srcData[(srcUpY * srcWidth + srcLeftX)*pixelSize + k];
					const auto ldPixelPart = (1 - u)*v*srcData[(srcDownY * srcWidth + srcLeftX)*pixelSize + k];
					const auto ruPixelPart = u * (1 - v) * srcData[(srcUpY * srcWidth + srcRightX)*pixelSize + k];
					const auto rdPixelPart = u * v * srcData[(srcDownY * srcWidth + srcRightX)*pixelSize + k];

					const auto pixel = luPixelPart + ldPixelPart + ruPixelPart + rdPixelPart;
					dstData[(dstY * dstWidth + dstX)*pixelSize + k] = pixel>255 ? 255 : static_cast<unsigned char>(pixel);
				}
			}
		}
	}
	else
	{
		assert(false);
		return false;
	}
	return true;
}