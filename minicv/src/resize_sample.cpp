#include <cassert>
#include "common_define.h"
#include "resize.h"
#include "../3rd/opencv/include/opencv2/opencv.hpp"

#if BUILD_SAMPLE
void resize_sample()
{
	const cv::Mat src = cv::imread("F:/MyOpenSource/minicv/minicv/resource/two_grils.png"); //cv::IMREAD_GRAYSCALE
	if (!src.data)
	{
		return;
	}
	cv::Mat dst(src.rows/2, src.cols/2, src.type());
	if (src.type() == CV_8UC3)
	{
		resize(src.data, src.cols, src.rows,3,RESIZE_METHOD::RESIZE_DLEARNER,dst.data,dst.cols,dst.rows);
	}
	else if (src.type() == CV_8UC1)
	{
		resize(src.data, src.cols, src.rows, 1, RESIZE_METHOD::RESIZE_NEAREST, dst.data, dst.cols, dst.rows);
	}
	else
	{
		assert(false);
	}

	cv::imshow("two grils", src);
	cv::imshow("two grils threshold", dst);
	cv::waitKey(0);
}
#endif //BUILD_SAMPLE