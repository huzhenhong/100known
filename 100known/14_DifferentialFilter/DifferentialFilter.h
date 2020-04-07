//
// Created by huluwa on 20-4-6.
//

#ifndef INC_100KNOWN_DIFFERENTIALFILTER_H
#define INC_100KNOWN_DIFFERENTIALFILTER_H

cv::Mat DifferentialFilterMaunal(const cv::Mat & src, bool bHorizontial = false)
{
    cv::Mat dst = cv::Mat::zeros(src.size(), src.type());

    // 生产差分核
    float kernel[3][3] = {{0, -1, 0}, {0, 1, 0}, {0, 0, 0}};

    if (bHorizontial)
    {
        kernel[0][1] = 0;
        kernel[1][0] = -1;
    }

    int origin = 1;

    // 滤波操作
    for (int y = 0; y < src.rows; ++y)
    {
        for (int x = 0; x < src.cols; ++x)
        {
			float value = 0;
			for (int dy = -origin; dy < origin + 1; ++dy)
			{
				for (int dx = -origin; dx < origin + 1; ++dx)
				{
					if (((dx + x) >= 0) && ((dy + y) >= 0))
					{
						// 对应坐标相乘
						value += (float)src.at<uchar>(y + dy, x + dx) * kernel[dy + origin][dx + origin];
					}
				}
			}

			value = fmax(value, 0); // 负数置为0
			dst.at<uchar>(y, x) = (uchar)value;
        }
    }

    return dst;
}

#endif //INC_100KNOWN_DIFFERENTIALFILTER_H
