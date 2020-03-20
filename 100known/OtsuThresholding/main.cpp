//
// Created by huluwa on 20-3-20.
//
#include "tool.h"
#include "OtsuThresholding.h"


int main()
{
    cv::Mat src = cv::imread("../../OtsuThresholding/lena.jpg");
    if(src.empty())
    {
        std::cout << "Load image failed!" << std::endl;
        return -1;
    }

    cv::Mat gray;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);

    auto dst1 = Run("OtsuThresholdingByManual", OtsuThresholdingByManual, gray);
    cv::hconcat(gray, dst1, dst1);
    Show("OtsuThresholdingByManual", dst1);

    auto dst2 = Run("OtsuThresholdingByThreshold", OtsuThresholdingByThreshold, gray);
    cv::hconcat(gray, dst2, dst2);
    Show("OtsuThresholdingByThreshold", dst2);

    cv::waitKey();

    return 0;
}