//
// Created by huluwa on 20-3-20.
//

#ifndef INC_100KNOWN_THRESHOLDING_H
#define INC_100KNOWN_THRESHOLDING_H

#include "opencv2/opencv.hpp"

cv::Mat ThreshouldingByManual(cv::Mat & src)
{
    cv::Mat dst = cv::Mat::zeros(src.size(), src.type());

    for (auto y = 0; y < src.rows; ++y)
    {
        for (auto x = 0; x < src.cols; ++x)
        {
            if(src.at<uchar>(x, y) > 128)
            {
                dst.at<uchar>(x, y) = 255;
            }
            else
            {
                dst.at<uchar>(x, y) = 0;
            }
        }
    }

    return dst;
}


cv::Mat ThreshouldingByThreshold(cv::Mat & src)
{
    cv::Mat dst;
    cv::threshold(src, dst, 128, 255, cv::THRESH_BINARY);
    return dst;
}



#endif //INC_100KNOWN_THRESHOLDING_H
