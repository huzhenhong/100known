//
// Created by huluwa on 20-4-6.
//

#include "../include/tool.h"
#include "DifferentialFilter.h"

int main()
{
    cv::Mat src = cv::imread("test.jpg");
    if (src.empty())
    {
        return -1;
    }

    cv::Mat gray;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);

    cv::Mat vertical = DifferentialFilterMaunal(gray);
    Show("vertical", vertical);

    cv::Mat horizontial = DifferentialFilterMaunal(gray, true);
    Show("horizontial", horizontial);

    cv::waitKey();
    cv::destroyAllWindows();

    return 0;
}
