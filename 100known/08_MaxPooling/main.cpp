//
// Created by huluwa on 2020/3/30.
//

#include "MaxPooling.h"
#include "tool.h"

int main()
{
    cv::Mat src = cv::imread("../../test.jpg");
    if (src.empty())
    {
        return -1;
    }

    // 自定义
    cv::Mat max_pooling = Run("MaxPooling", MaxPooling, src);
    cv::imwrite("max_pooling.jpg", max_pooling);

    cv::Mat dsd = cv::imread("max_pooling.jpg");
    Show("MaxPooling", dsd);

    cv::waitKey();
    cv::destroyAllWindows();

    return 0;
}
