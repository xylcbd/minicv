#include <memory>
#include "common_define.h"
#include "threshold.h"
#include "common_tools.h"
#include "../3rd/opencv/include/opencv2/opencv.hpp"

using namespace cv;

#if BUILD_SAMPLE
void threshold_sample()
{
	const Mat src = imread("F:/MyOpenSource/minicv/minicv/resource/two_grils.png", IMREAD_GRAYSCALE);
	if (!src.data)
	{
		return;
	}
	Mat dst = src;
	threshold(src.data, src.cols, src.rows, 60, 0, 255, dst.data);

	imshow("two grils", src);
	imshow("two grils threshold", dst);
	waitKey(0);
}
#endif //BUILD_SAMPLE