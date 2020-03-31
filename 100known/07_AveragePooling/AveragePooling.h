//
// Created by huluwa on 2020/3/30.
//

#ifndef INC_100KNOWN_AVERAGEPOOLING_H
#define INC_100KNOWN_AVERAGEPOOLING_H

#include "opencv2/opencv.hpp"

cv::Mat AveragePoolingByManaul(const cv::Mat & src)
{
    int ksize = 3;
    cv::Mat dst = cv::Mat::zeros(src.size(), src.type());

    if (ksize < 0 || ksize > src.rows || ksize > src.cols)
    {
        return dst;
    }

    for (int y = 0; y < src.rows; y += ksize)
    {
        for (int x = 0; x < src.cols; x += ksize)
        {
            // 每个通道
            for (int c = 0; c < src.channels(); ++c)
            {
                // 将kernel内的所有像素值累加
                unsigned int sum = 0;
                for (int dy = 0; dy < ksize; ++dy)
                {
                    for (int dx = 0; dx < ksize; ++dx)
                    {
                        sum += src.at<cv::Vec3b>(y + dy, x + dx)[c];
                    }
                }

                // 然后求平均后再赋值给每一个像素
                auto average = (uchar)(sum / (ksize * ksize));
                for (int dy = 0; dy < ksize; ++dy)
                {
                    for (int dx = 0; dx < ksize; ++dx)
                    {
                        dst.at<cv::Vec3b>(y + dy, x + dx)[c] = average;
                    }
                }
            }
        }
    }

    return dst;
}

#endif //INC_100KNOWN_AVERAGEPOOLING_H
