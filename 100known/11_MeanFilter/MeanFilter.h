//
// Created by huluwa on 20-4-4.
//

#ifndef INC_100KNOWN_MAX_MINFILTER_H
#define INC_100KNOWN_MEANFILTER_H

cv::Mat MeanFilterMaunal(const cv::Mat & src, int ksize = 3)
{
    assert((ksize > 0) && (1 == (ksize % 2)) && (!src.empty()));

    cv::Mat dst = cv::Mat::zeros(src.size(), src.type());

    // 确定核中心点
    int origin = floor(ksize / 2);

    // 滤波操作
    for (int y = 0; y < src.rows; ++y)
    {
        for (int x = 0; x < src.cols; ++x)
        {
            for (int c = 0; c < src.channels(); ++c)
            {
                int sum = 0;

                for (int dy = -origin; dy < origin + 1; ++dy)
                {
                    for (int dx = -origin; dx < origin + 1; ++dx)
                    {
                        if (((dx + x) >= 0) && ((dy + y) >= 0))
                        {
                            sum += src.at<cv::Vec3b>(y + dy, x + dx)[c];
                        }
                    }
                }

                dst.at<cv::Vec3b>(y, x)[c] = (uchar)(sum / (ksize * ksize));
            }
        }
    }

    return dst;
}

cv::Mat MeanFilterOpenCV(const cv::Mat & src, int ksize)
{
    assert((ksize > 0) && (1 == (ksize % 2)) && (!src.empty()));

    cv::Mat dst = cv::Mat::zeros(src.size(), src.type());

    cv::blur(src, dst, cv::Size(ksize, ksize));

    return dst;
}


#endif //INC_100KNOWN_MOTIONFILTER_H
