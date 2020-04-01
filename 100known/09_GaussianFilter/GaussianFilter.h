//
// Created by huluwa on 2020/4/1.
//

#ifndef INC_100KNOWN_GAUSSIANFILTER_H
#define INC_100KNOWN_GAUSSIANFILTER_H

#include "opencv2/opencv.hpp"
#include <cmath>

cv::Mat GaussianFilterMaunal(const cv::Mat & src, int ksize = 3, float sigma = 1.0)
{
    assert((ksize > 0) && (1 == (ksize % 2)) && (!src.empty()));

    cv::Mat dst = cv::Mat::zeros(src.size(), src.type());

    // 生产高斯核
    int origin = floor(ksize / 2);
    float kernel[ksize][ksize];

    float sum = 0;
    for (int y = 0; y < ksize; ++y)
    {
        for (int x = 0; x < ksize; ++x)
        {
            int u = y - origin;
            int v = x - origin;

            kernel[y][x] = 1 / (2*M_PI*sigma*sigma) * exp(-(u*u + v*v) / (2*sigma*sigma));
            sum += kernel[y][x];
        }
    }

    // 核归一化
    for (int y = 0; y < ksize; ++y)
    {
        for (int x = 0; x < ksize; ++x)
        {
            kernel[y][x] /= sum;
        }
    }

    // 滤波操作
    for (int y = 0; y < src.rows; ++y)
    {
        for (int x = 0; x < src.cols; ++x)
        {
            for (int c = 0; c < src.channels(); ++c)
            {
                float value = 0;
                for (int dy = -origin; dy < origin + 1; ++dy)
                {
                    for (int dx = -origin; dx < origin + 1; ++dx)
                    {
                        if (((dx + x) >= 0) && ((dy + y) >= 0))
                        {
                            // 对应坐标相乘
                            value += (float)src.at<cv::Vec3b>(y + dy, x + dx)[c] * kernel[dy + origin][dx + origin];
                        }
                    }

                    dst.at<cv::Vec3b>(y, x)[c] = (uchar)value;
                }
            }
        }
    }

    return dst;
}

cv::Mat GaussianFilterOpenCV(const cv::Mat & src, int ksize, float sigma)
{
    assert((ksize > 0) && (1 == (ksize % 2)) && (!src.empty()));

    cv::Mat dst = cv::Mat::zeros(src.size(), src.type());

    cv::GaussianBlur(src, dst, cv::Size(ksize, ksize), sigma);

    return dst;
}


#endif //INC_100KNOWN_GAUSSIANFILTER_H
