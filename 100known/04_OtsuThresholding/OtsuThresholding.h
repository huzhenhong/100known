//
// Created by huluwa on 20-3-20.
//

#ifndef INC_100KNOWN_OTSUTHRESHOLDING_H
#define INC_100KNOWN_OTSUTHRESHOLDING_H

#include "opencv2/opencv.hpp"

cv::Mat OtsuThresholdingByManual(cv::Mat & src)
{
    cv::Mat dst = cv::Mat::zeros(src.size(), src.type());
    double maxVariance = 0.0;
    uchar bestThresh = 0;

    // 计算出最佳阈值
    for(int thresh = 0; thresh < 255; ++thresh)
    {
        std::vector<uchar> overtopVec, underVec;

        for(auto y = 0; y < src.rows; ++y)
        {
            for(auto x = 0; x < src.cols; ++x)
            {
                uchar point = src.at<uchar>(y, x);
                if(point > thresh)
                {
                    overtopVec.emplace_back(point);
                }
                else
                {
                    underVec.emplace_back(point);
                }
            }
        }

        double p0 = 1.0 * overtopVec.size() / (src.rows * src.cols);
        double p1 = 1.0 * underVec.size() / (src.rows * src.cols);

        double x0 = 0.0;
        if(!underVec.empty())
        {
            for_each(overtopVec.begin(), overtopVec.end(), [&x0](auto item){x0 += item;});
            x0 = x0 / overtopVec.size();
        }

        double x1 = 0.0;
        if(!underVec.empty())
        {
            for_each(underVec.begin(), underVec.end(), [&x1](auto item){x1 += item;});
            x1 = x1 / underVec.size();
        }

        double variance = 2 * p0 * p1 * std::pow((x0 - x1), 2);

        if(variance > maxVariance)
        {
            maxVariance = variance;
            bestThresh = thresh;
        }
    }

    // 根据最佳阈值进行二值化
    for(auto y = 0; y < src.rows; ++y)
    {
        for(auto x = 0; x < src.cols; ++x)
        {
            if(*src.ptr(y, x) > bestThresh)
            {
                dst.at<uchar>(y, x) = 255;
            }
        }
    }

    return dst;
}


cv::Mat OtsuThresholdingByThreshold(cv::Mat & src)
{
    cv::Mat dst;
    cv::threshold(src, dst, 0, 255, cv::THRESH_OTSU);
    return dst;
}


#endif //INC_100KNOWN_OTSUTHRESHOLDING_H
