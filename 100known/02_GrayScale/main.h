//
// Created by huluwa on 20-3-20.
//

#ifndef INC_100KNOWN_MAIN_H
#define INC_100KNOWN_MAIN_H

#include "opencv2/opencv.hpp"

// RGB转灰度公式 0.2126 * r + 0.7152 * g + 0.072 * b
cv::Mat ScaleByManual(cv::Mat & src)
{
    cv::Mat dst = cv::Mat::zeros(src.size(), CV_8UC1);

    for (auto y = 0; y < src.rows; ++y)
    {
        for (auto x = 0; x < src.cols; ++x)
        {
            auto points = src.at<cv::Vec3b>(y, x);
            dst.at<uchar>(y, x) = (uchar)(0.2126 * points[2] + 0.7152 * points[1] + 0.072 * points[0]);
        }
    }

    return dst;
}


cv::Mat ScaleBycvtColor(cv::Mat & src)
{
    cv::Mat dst;
    cv::cvtColor(src, dst, cv::COLOR_BGR2GRAY);
    return dst;
}


#endif //INC_100KNOWN_MAIN_H
