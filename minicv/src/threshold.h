#ifndef _THRESHOLD_H_
#define _THRESHOLD_H_
#include "platform_info.h"

//gray -> binaryzation
API_DESC bool threshold(const unsigned char* srcData, const int width, const int height, 
	const unsigned char thrshold, const unsigned char low, const unsigned char high, unsigned char* dstData);

//gray -> binaryzation
API_DESC bool ostuThreshold(const unsigned char* srcData, const int width, const int height,
	const unsigned char low, const unsigned char high, unsigned char* dstData);

#endif //_THRESHOLD_H_