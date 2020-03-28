//
// Created by huluwa on 20-3-27.
//

#include "tool.h"
#include "opencv2/opencv.hpp"

using namespace cv;

Mat ReduceColor(const Mat & src)
{
    Mat dst = Mat::zeros(src.size(), src.type());

    for (int y = 0; y < src.rows; ++y)
    {
        for (int x = 0; x < src.cols; ++x)
        {
            for (int ch = 0; ch < src.channels(); ++ch)
            {
                dst.at<Vec3b>(y, x)[ch] = (uchar)(floor((float)src.at<Vec3b>(y, x)[ch] / 64) * 64 + 32);
            }
        }
    }

    return dst;
}

int main()
{
    Mat src = imread("../../test.jpg", IMREAD_COLOR);
    if (src.empty())
    {
        return -1;
    }

    Mat dst = Run("ReduceColor", ReduceColor, src);
    if (!dst.empty())
    {
        Show("ReduceColor", dst);
    }

    waitKey();
    destroyAllWindows();

    return 0;
}