//
// Created by huluwa on 20-4-4.
//

#include "../include/tool.h"
#include "Max-MinFilter.h"

int main()
{
    cv::Mat src = cv::imread("../../imori.jpg");
    if (src.empty())
    {
        return -1;
    }

    cv::Mat gray;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);

    cv::Mat manual = MaxMinFilterMaunal(gray, 3);
    cv::hconcat(gray, manual, manual);
    Show("MaxMinFilterMaunal", manual);

    cv::waitKey();
    cv::destroyAllWindows();

    return 0;
}