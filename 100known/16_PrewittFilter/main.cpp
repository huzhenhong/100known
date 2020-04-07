//
// Created by huluwa on 20-4-6.
//

#include "../include/tool.h"
#include "PrewittFilter.h"

int main()
{
    cv::Mat src = cv::imread("../../imori.jpg");
    if (src.empty())
    {
        return -1;
    }

    cv::Mat gray;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);

    cv::Mat manual_vertical = PrewittlFilterMaunal(gray);
    Show("manual_vertical", manual_vertical);

    cv::Mat manual_horizontial = PrewittlFilterMaunal(gray, true);
    Show("manual_horizontial", manual_horizontial);

    cv::Mat opencv_vertical = PrewittFilterOpenCV(gray);
    Show("opencv_vertical", opencv_vertical);

    cv::Mat opencv_horizontial = PrewittFilterOpenCV(gray, true);
    Show("opencv_horizontial", opencv_horizontial);

    cv::waitKey();
    cv::destroyAllWindows();

    return 0;
}
