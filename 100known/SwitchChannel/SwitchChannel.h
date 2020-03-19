//
// Created by huluwa on 20-3-18.
//

#ifndef INC_100KNOWN_SWITCHCHANNEL_H
#define INC_100KNOWN_SWITCHCHANNEL_H

#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/core.hpp"


cv::Mat SwitchByManual(cv::Mat & src)
{
    // 在内存中每一行的像素是连续的，但是行之间不一定是连续的
    cv::Mat dst = cv::Mat::zeros(src.size(), src.type());
    for (auto y = 0; y < src.rows; ++y)
    {
        for (auto x = 0; x < src.cols; ++x)
        {
            // BGR=>RGB, cost: 0.00128591s
            dst.at<cv::Vec3b>(y, x)[0] = src.at<cv::Vec3b>(y, x)[2];
            dst.at<cv::Vec3b>(y, x)[1] = src.at<cv::Vec3b>(y, x)[1];
            dst.at<cv::Vec3b>(y, x)[2] = src.at<cv::Vec3b>(y, x)[0];

            // Cost time : 0.000815532，不用拷贝G通道，要快1/3
            // std::swap(src.at<cv::Vec3b>(y, x)[2], src.at<cv::Vec3b>(y, x)[0]);
        }
    }

    return dst;
}

cv::Mat SwitchBySplitAndMerge(const cv::Mat & src)
{
    std::vector<cv::Mat> channels;
    cv::split(src, channels);

    std::swap(channels[0], channels[2]);

    cv::Mat dst = cv::Mat::zeros(src.size(), src.type());

    cv::merge(channels, dst);

    return dst; // cost time : 0.000818813
}

cv::Mat SwitchByMixChannels(const cv::Mat & src)
{
    cv::Mat dst(src.size(), src.type());

    std::vector<int> fromTo = {0, 2, 1, 1, 2, 0};

    cv::mixChannels(src, dst, fromTo);

    return dst; // cost time : 0.000624895

}

#endif //INC_100KNOWN_SWITCHCHANNEL_H
