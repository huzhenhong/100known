//
// Created by huluwa on 20-4-4.
//

#ifndef INC_100KNOWN_MAX_MINFILTER_H
#define INC_100KNOWN_MOTIONFILTER_H

cv::Mat MotionFilterMaunal(const cv::Mat & src, int ksize = 3)
{
    assert((ksize > 0) && (1 == (ksize % 2)) && (!src.empty()));

    cv::Mat dst = cv::Mat::zeros(src.size(), src.type());

    // 生产滤波核
    std::vector<float> kernel(ksize * ksize);
    for (int i = 0; i < ksize; ++i)
    {
        for (int j = 0; j < ksize; ++j)
        {
            if (i == j)
            {
                kernel[i * ksize + j] = 1.0 / ksize;
            }
        }
    }

    // 滤波核中心
    int origin = floor(ksize / 2);

    // 滤波操作
    for (int y = 0; y < src.rows; ++y)
    {
        for (int x = 0; x < src.cols; ++x)
        {
            for (int c = 0; c < src.channels(); ++c)
            {
                float value = 0;

                for (int dy = -origin; dy < origin + 1; ++dy)
                {
                    for (int dx = -origin; dx < origin + 1; ++dx)
                    {
                        if (((dx + x) >= 0) && ((dy + y) >= 0))
                        {
                            value += src.at<cv::Vec3b>(y + dy, x + dx)[c] * kernel[(dy + origin) * ksize + dx + origin];
                        }
                    }
                }

                dst.at<cv::Vec3b>(y, x)[c] = (uchar)value;
            }
        }
    }

    return dst;
}

cv::Mat MotionFilterOpenCV(const cv::Mat & src, int ksize)
{
    assert((ksize > 0) && (1 == (ksize % 2)) && (!src.empty()));

    cv::Mat dst = cv::Mat::zeros(src.size(), src.type());

    cv::Mat kernel = cv::Mat::zeros(ksize, ksize, CV_32F);
    for (int i = 0; i < ksize; ++i)
    {
        kernel.at<float>(i, i) = 1.0 / ksize;
    }

    cv::filter2D(src, dst, src.depth(), kernel);
    cv::blur(src, dst, cv::Size(ksize, ksize));

    return dst;
}


#endif //INC_100KNOWN_MAX_MINFILTER_H
