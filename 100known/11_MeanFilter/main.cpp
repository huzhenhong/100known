//
// Created by huluwa on 20-4-4.
//

#include "../include/tool.h"
#include "MeanFilter.h"

int main()
{
    cv::Mat src = cv::imread("../../lena.jpg");
    if (src.empty())
    {
        return -1;
    }

    cv::Mat manual = MeanFilterMaunal(src, 3);
    cv::hconcat(src, manual, manual);
    Show("MeanFilterMaunal", manual);

    cv::Mat opencv = MeanFilterOpenCV(src, 3);
    cv::hconcat(src, opencv, opencv);
    Show("MeanFilterOpenCV", opencv);

    cv::waitKey();
    cv::destroyAllWindows();

    return 0;
}