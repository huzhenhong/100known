//
// Created by huluwa on 20-4-4.
//

#ifndef INC_100KNOWN_MAX_MINFILTER_H
#define INC_100KNOWN_MAX_MINFILTER_H

cv::Mat MaxMinFilterMaunal(const cv::Mat & src, int ksize = 3)
{
    assert((ksize > 0) && (1 == (ksize % 2)) && (!src.empty()));

    cv::Mat dst = cv::Mat::zeros(src.size(), src.type());

    // 滤波核中心
    int origin = floor(ksize / 2);

    // 滤波操作
    for (int y = 0; y < src.rows; ++y)
    {
        for (int x = 0; x < src.cols; ++x)
        {
            uchar maxVal = 0;
            uchar minVal = 255;

            for (int dy = -origin; dy < origin + 1; ++dy)
            {
                for (int dx = -origin; dx < origin + 1; ++dx)
                {
                    if (((dx + x) >= 0) && ((dy + y) >= 0))
                    {
                        uchar val = src.at<uchar>(y + dy, x + dx);
                        if (val > maxVal)
                            maxVal = val;
                        if (val < minVal)
                            minVal = val;
                    }
                }
            }

            dst.at<uchar>(y, x) = maxVal - minVal;
        }
    }

    return dst;
}

#endif //INC_100KNOWN_MAX_MINFILTER_H
