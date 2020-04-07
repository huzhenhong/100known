//
// Created by huluwa on 2020/4/1.
//

#include "../include/tool.h"
#include "LoGFilter.h"

int main()
{
    cv::Mat src = cv::imread("../../noise.jpg");
    if(src.empty())
    {
        return -1;
    }

    cv::Mat gray = src;
//    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);

    cv::Mat manual_1 = LoGFilterMaunal(gray, 5, 1);
    cv::Mat manual_3 = LoGFilterMaunal(gray, 5, 3);
    cv::Mat manual_5 = LoGFilterMaunal(gray, 5, 5);

    cv::hconcat(gray, manual_1, manual_1);
    cv::hconcat(manual_1, manual_3, manual_3);
    cv::hconcat(manual_3, manual_5, manual_5);
    Show("LoGFilterMaunal", manual_5);


    cv::waitKey();
    cv::destroyAllWindows();

    return 0;
}