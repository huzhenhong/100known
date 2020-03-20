//
// Created by huluwa on 20-3-19.
//
#include "tool.h"
#include "GrayScale.h"


int main()
{
    cv::Mat src = cv::imread("../../GrayScale/lena.jpg");
    if(src.empty())
    {
        std::cout << "Load src img failed." << std::endl;
        return -1;
    }

    auto dst1 = Run("ScaleByManual", ScaleByManual, src);
    Show("ScaleByManual", dst1);

    auto dst2 = Run("ScaleBycvtColor", ScaleBycvtColor, src);
    Show("ScaleBycvtColor", dst2);

    cv::waitKey();
    cv::destroyAllWindows();
    return 0;
}
