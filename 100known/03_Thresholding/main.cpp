//
// Created by huluwa on 20-3-20.
//

#include "tool.h"
#include "Thresholding.h"


int main()
{
    cv::Mat src = cv::imread("../../Thresholding/lena.jpg");
    if(src.empty())
    {
        std::cout << "load image failed!" << std::endl;
    }

    cv::Mat gray;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);

    cv::Mat dst1 = Run("ThreshouldingByManual", ThreshouldingByManual, gray);
    Show("ThreshouldingByManual", dst1);

    cv::Mat dst2 = Run("ThreshouldingByThreshold", ThreshouldingByThreshold, gray);
    Show("ThreshouldingByThreshold", dst2);

    cv::waitKey();
    cv::destroyAllWindows();
    return 0;
}