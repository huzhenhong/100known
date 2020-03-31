//
// Created by huluwa on 20-3-20.
//

#ifndef INC_100KNOWN_TOOL_H
#define INC_100KNOWN_TOOL_H

#include "opencv2/opencv.hpp"

template <typename Func, typename T>
T Run(const std::string & funcName, const Func & func, T param)
{
    // 开始计时
    int64 startTime = cv::getTickCount();

    auto result = func(param);

    // 停止计时
    int64 endTime = cv::getTickCount();
    double costTime = (double)(endTime - startTime) / cv::getTickFrequency();
    std::cout << funcName <<  " cost time : " << costTime << std::endl;

    return result;
}


void Show(const std::string & name, const cv::Mat & img)
{
    cv::namedWindow(name, cv::WINDOW_NORMAL);
    cv::imshow(name, img);
}
#endif //INC_100KNOWN_TOOL_H
