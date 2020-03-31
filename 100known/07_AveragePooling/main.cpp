//
// Created by huluwa on 2020/3/30.
//

#include "AveragePooling.h"
#include "tool.h"

int main()
{
    cv::Mat src = cv::imread("../../test.jpg");
    if (src.empty())
    {
        return -1;
    }

    // 自定义
    cv::Mat average_pooling = Run("AveragePoolingByManaul", AveragePoolingByManaul, src);
    cv::imwrite("average_pooling.jpg", average_pooling);

    cv::Mat dsd = cv::imread("average_pooling.jpg");
    Show("AveragePoolingByManaul", dsd);

    cv::waitKey();
    cv::destroyAllWindows();

    return 0;
}
