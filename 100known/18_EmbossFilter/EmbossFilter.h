//
// Created by huluwa on 20-4-6.
//

#ifndef INC_100KNOWN_DIFFERENTIALFILTER_H
#define INC_100KNOWN_DIFFERENTIALFILTER_H

cv::Mat EmbossFilterMaunal(const cv::Mat & src, bool bHorizontial = false)
{
    cv::Mat dst = cv::Mat::zeros(src.size(), src.type());

    cv::Mat kernel = (cv::Mat_<float>(3, 3) << -2, -1, 0, -1, 1, 1, 0, 1, 2);

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
						value += (float)src.at<uchar>(y + dy, x + dx) * kernel.at<float>(dy + origin, dx + origin);
					}
				}
			}
			
			value = fmax(value, 0); // 负数置为0
			value = fmin(value, 255); // 大于255的置为255
			dst.at<uchar>(y, x) = (uchar)value;
        }
    }

    return dst;
}

cv::Mat EmbossFilterOpenCV(const cv::Mat & src)
{
    cv::Mat dst;
    cv::Mat kernel = (cv::Mat_<float>(3, 3) << -2, -1, 0, -1, 1, 1, 0, 1, 2);
    cv::filter2D(src, dst, -1, kernel);

    return dst;
}

#endif //INC_100KNOWN_DIFFERENTIALFILTER_H