//
// Created by huluwa on 20-4-6.
//

#include "../include/tool.h"
#include "EmbossFilter.h"

int main()
{
    cv::Mat src = cv::imread("../../imori.jpg");
    if (src.empty())
    {
        return -1;
    }

    cv::Mat gray;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);

    cv::Mat manual = EmbossFilterMaunal(gray);
    cv::Mat opencv = EmbossFilterOpenCV(gray);

    cv::Mat dst;
    cv::hconcat(gray, manual, dst);
    cv::hconcat(dst, opencv, dst);
    
    Show("dst", dst);

    cv::waitKey();
    cv::destroyAllWindows();

    return 0;
}
