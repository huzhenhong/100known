//
// Created by huluwa on 2020/4/1.
//

#ifndef INC_100KNOWN_MAXPOOLING_H
#define INC_100KNOWN_MAXPOOLING_H

#include "opencv2/opencv.hpp"

cv::Mat MaxPooling(const cv::Mat & src)
{
    cv::Mat dst = src.clone();

    int ksize = 3;

    for (int y = 0; y < src.rows; y+=ksize)
    {
        for (int x = 0 ; x < src.cols; x += ksize)
        {
            for ( int c = 0; c < src.channels(); ++c)
            {
                uchar maxValue = 0;
                for (int dy = 0; dy < ksize; ++dy)
                {
                    for (int dx = 0; dx < ksize; ++dx)
                    {
                        if (src.at<cv::Vec3b>(y+dy, x+dx)[c] > maxValue)
                        {
                            maxValue = src.at<cv::Vec3b>(y+dy, x+dx)[c];
                        }
                    }
                }

                for (int dy = 0; dy < ksize; ++dy)
                {
                    for (int dx = 0; dx < ksize; ++dx)
                    {
                        dst.at<cv::Vec3b>(y+dy, x+dx)[c] = maxValue;
                    }
                }
            }
        }
    }

    return dst;
}

#endif //INC_100KNOWN_MAXPOOLING_H
