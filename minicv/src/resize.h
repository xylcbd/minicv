#ifndef _RESIZE_H_
#define _RESIZE_H_
#include "platform_info.h"

//resize
enum class RESIZE_METHOD
{
	RESIZE_NEAREST, //
	RESIZE_DLEARNER //
};
API_DESC bool resize(const unsigned char* srcData, const int srcWidth, const int srcHeight,
	const int pixelSize,const RESIZE_METHOD resizeMethod,
	unsigned char* dstData, const int dstWidth, const int dstHeight);

#endif //_RESIZE_H_