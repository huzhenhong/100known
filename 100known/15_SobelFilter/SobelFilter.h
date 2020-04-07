//
// Created by huluwa on 20-4-6.
//

#ifndef INC_100KNOWN_DIFFERENTIALFILTER_H
#define INC_100KNOWN_DIFFERENTIALFILTER_H

cv::Mat SobelFilterMaunal(const cv::Mat & src, bool bHorizontial = false)
{
    cv::Mat dst = cv::Mat::zeros(src.size(), src.type());

    // sobel算子
    float kernel[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    if (bHorizontial)
    {
        kernel[0][1] = 0;
        kernel[0][2] = 1;
        kernel[1][0] = -2;
        kernel[1][2] = 2;
        kernel[2][0] = -1;
        kernel[2][1] = 0;
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

cv::Mat SobelFilterOpenCV(const cv::Mat & src, bool bHorizontial = false)
{
    cv::Mat dst;
    if (bHorizontial)
    {
        cv::Sobel(src, dst, -1, 1, 0, 3);
    }
    else
    {
        cv::Sobel(src, dst, -1, 0, 1, 3);
    }

    return dst;
}

#endif //INC_100KNOWN_DIFFERENTIALFILTER_H
