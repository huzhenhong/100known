//
// Created by huluwa on 2020/4/1.
//

#include "tool.h"
#include "GaussianFilter.h"

int main()
{
    cv::Mat src = cv::imread("../../lena.jpg");
    if(src.empty())
    {
        return -1;
    }

    cv::Mat manual = GaussianFilterMaunal(src, 3, 1.3);
    cv::hconcat(src, manual, manual);
    Show("GaussianFilterMaunal", manual);

    cv::Mat opencv = GaussianFilterOpenCV(src, 3, 1.3);
    cv::hconcat(src, opencv, opencv);
    Show("GaussianFilterOpenCV", opencv);

    cv::waitKey();
    cv::destroyAllWindows();

    return 0;
}