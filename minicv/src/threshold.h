#ifndef _THRESHOLD_H_
#define _THRESHOLD_H_
#include "platform_info.h"

//gray -> binaryzation
API_DESC bool threshold(const unsigned char* srcData, const int width, const int height, 
	const int threshold, const unsigned char low,const unsigned char high,unsigned char* dstData);

#endif //_THRESHOLD_H_