#ifndef _COLOR_CONVER_H_
#define _COLOR_CONVER_H_
#include "platform_info.h"

//rgb -> gray
API_DESC bool rgb24ToGray(const unsigned char* srcData, const int width, const int height, unsigned char* dstData);
//rgba -> gray
API_DESC bool rgba32ToGray(const unsigned char* srcData, const int width, const int height, unsigned char* dstData);
//argb -> gray
API_DESC bool argb32ToGray(const unsigned char* srcData, const int width, const int height, unsigned char* dstData);

#endif //_COLOR_CONVER_H_