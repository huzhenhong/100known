//
// Created by huluwa on 2020/3/19.
//

#ifndef INC_100KNOWN_TOOL_H
#define INC_100KNOWN_TOOL_H

#include "opencv2/opencv.hpp"

void Show(const std::string & winName, const cv::Mat & img)
{
    cv::namedWindow(winName, cv::WINDOW_NORMAL);
    cv::imshow(winName, img);
}

template <typename Func, typename T>
T Run(const std::string & funcName, const Func & func, T & srcImg)
{
    // 开始计时
    int64 startTime = cv::getTickCount();

    auto result = func(srcImg);

    // 停止计时
    int64 endTime = cv::getTickCount();
    double costTime = (double)(endTime - startTime) / cv::getTickFrequency();
    std::cout << funcName <<  " cost time : " << costTime << std::endl;

    return result;
}


#endif //INC_100KNOWN_TOOL_H
