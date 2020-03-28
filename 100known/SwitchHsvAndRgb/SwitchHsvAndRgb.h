//
// Created by huluwa on 20-3-25.
//

#ifndef INC_100KNOWN_SWITCHHSVANDRGB_H
#define INC_100KNOWN_SWITCHHSVANDRGB_H

#include "opencv2/opencv.hpp"

cv::Mat Bgr2HsvByManual(cv::Mat & src)
{
    cv::Mat dst = cv::Mat::zeros(src.size(), CV_32FC3);

    for(int y = 0; y < src.rows; ++y)
    {
        for(int x = 0; x < src.cols; ++x)
        {
            float r = (float)src.at<cv::Vec3b>(y, x)[2] / 255;
            float g = (float)src.at<cv::Vec3b>(y, x)[1] / 255;
            float b = (float)src.at<cv::Vec3b>(y, x)[0] / 255;

            float max = std::max(std::max(r, g), b);
            float min = std::min(std::min(r, g), b);

            // 色相
            float h = 0;

            if (min == max)
            {
                h = 0;
            }
            else if (min == b)
            {
                h = 60 * (g - r) / (max - min) + 60;
            }
            else if (min == r)
            {
                h = 60 * (b - g) / (max - min) + 180;
            }
            else if (min == g)
            {
                h = 60 * (r - b) / (max - min) + 300;
            }


            // 饱和度
            float s = max - min;

            // 明度
            float v = max;

            dst.at<cv::Vec3f>(y, x)[0] = h;
            dst.at<cv::Vec3f>(y, x)[1] = s;
            dst.at<cv::Vec3f>(y, x)[2] = v;
        }
    }

    return dst;
}


cv::Mat Bgr2HsvByCvtcolor(cv::Mat & src)
{
    cv::Mat dst = cv::Mat::zeros(src.size(), CV_8UC3);
    cv::cvtColor(src, dst, cv::COLOR_BGR2HSV);
    return dst;
}


cv::Mat Hsv2BgrByManual(cv::Mat & src)
{
    cv::Mat dst = cv::Mat::zeros(src.size(), CV_8UC3);

    for (int y = 0; y < src.rows; ++y)
    {
        for (int x = 0; x < src.cols; ++x)
        {
            float H = src.at<cv::Vec3f>(y, x)[0];
            float S = src.at<cv::Vec3f>(y, x)[1];
            float V = src.at<cv::Vec3f>(y, x)[2];

            float C = S;
            float H_ = H / 60;
            auto X = (float)(C * (1 - std::abs(std::fmod(H_, 2) - 1)));

            float R = V - C;
            float G = V - C;
            float B = V - C;

            if (H_ >= 0 && H_ < 1)
            {
                R += C;
                G += X;
            }
            else if (H_ >= 1 && H_ < 2)
            {
                R += X;
                G += C;
            }
            else if (H_ >= 2 && H_ < 3)
            {
                G += C;
                B += X;
            }
            else if (H_ >= 3 && H_ < 4)
            {
                G += X;
                B += C;
            }
            else if (H_ >= 4 && H_ < 5)
            {
                R += X;
                B += C;
            }
            else if (H_ >= 5 && H_ < 6)
            {
                R += C;
                B += X;
            }

            dst.at<cv::Vec3b>(y, x)[0] = (uchar)(B * 255);
            dst.at<cv::Vec3b>(y, x)[1] = (uchar)(G * 255);
            dst.at<cv::Vec3b>(y, x)[2] = (uchar)(R * 255);
        }
    }

    return dst;
}


cv::Mat Hsv2BgrByCvtcolor(cv::Mat & src)
{
    cv::Mat dst = cv::Mat::zeros(src.size(), CV_8UC3);
    cv::cvtColor(src, dst, cv::COLOR_HSV2BGR);
    return dst;
}


cv::Mat InverseHue(cv::Mat & src)
{
	cv::Mat dst = src.clone();
    for (int y = 0; y < src.rows; ++y)
    {
        for (int x = 0; x < src.cols; ++x)
        {
			dst.at<cv::Vec3f>(y, x)[0] = (float)std::fmod(src.at<cv::Vec3f>(y, x)[0] + 180, 360);
        }
    }

    return dst;
}

cv::Mat InverseHueForOpenCV(cv::Mat & src)
{
	// OpenCV的hsv是uchar
	cv::Mat dst = src.clone();
	for (int y = 0; y < src.rows; ++y)
	{
		for (int x = 0; x < src.cols; ++x)
		{
			dst.at<cv::Vec3b>(y, x)[0] = (uchar)std::fmod(src.at<cv::Vec3b>(y, x)[0] + 90, 180);
		}
	}

	return dst;
}

#endif //INC_100KNOWN_SWITCHHSVANDRGB_H
