#include <cassert>
#include "common_define.h"
#include "color_convert.h"
#include "../3rd/opencv/include/opencv2/opencv.hpp"

using namespace cv;

#if BUILD_SAMPLE
void color_convert_sample()
{
	const Mat src = imread("F:/MyOpenSource/minicv/minicv/resource/two_grils.png");
	if (!src.data)
	{
		return;
	}
	Mat dst(src.rows,src.cols, CV_8UC1);
	if (src.type() == CV_8UC3)
	{
		rgb24ToGray(src.data, src.cols, src.rows, dst.data);
	}
	else if (src.type() == CV_8UC4)
	{
		rgba32ToGray(src.data, src.cols, src.rows, dst.data);
	}
	else
	{
		assert(false);
	}

	imshow("two grils", src);
	imshow("two grils threshold", dst);
	waitKey(0);
}
#endif //BUILD_SAMPLE