//
// Created by huluwa on 20-4-4.
//

#include "../include/tool.h"
#include "MotionFilter.h"

int main()
{
    cv::Mat src = cv::imread("../../1.jpg");
    if (src.empty())
    {
        return -1;
    }

    cv::Mat manual = MotionFilterMaunal(src, 3);
    cv::hconcat(src, manual, manual);
    Show("MotionFilterMaunal", manual);

    cv::Mat opencv = MotionFilterOpenCV(src, 3);
    cv::hconcat(src, opencv, opencv);
    Show("MotionFilterOpenCV", opencv);

    cv::waitKey();
    cv::destroyAllWindows();

    return 0;
}