#include <memory>
#include "common_define.h"
#include "threshold.h"
#include "common_tools.h"
#include "../3rd/opencv/include/opencv2/opencv.hpp"

#if BUILD_SAMPLE
void threshold_sample()
{
	const cv::Mat src = cv::imread("F:/MyOpenSource/minicv/minicv/resource/two_grils.png", cv::IMREAD_GRAYSCALE);
	if (!src.data)
	{
		return;
	}
	cv::Mat dst = src;
	//threshold(src.data, src.cols, src.rows, 60, 0, 255, dst.data);
	ostuThreshold(src.data, src.cols, src.rows, 0, 255, dst.data);

	cv::imshow("two grils", src);
	cv::imshow("two grils threshold", dst);
	cv::waitKey(0);
}
#endif //BUILD_SAMPLE