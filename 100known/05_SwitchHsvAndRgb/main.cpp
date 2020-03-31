//
// Created by huluwa on 20-3-25.
//
#include "tool.h"
#include "SwitchHsvAndRgb.h"

int main()
{
	// 默认读取为BGR

    cv::Mat src = cv::imread("../../test.jpg");
    if(src.empty())
    {
        std::cout << "Load src img failed." << std::endl;
        return -1;
    }

    // 自己实现
    cv::Mat manual_hsv = Run("Bgr2HsvByManual", Bgr2HsvByManual, src);
    Show("Bgr2HsvByManual", manual_hsv);

	cv::Mat manual_inverse = Run("InverseHue", InverseHue, manual_hsv);
    Show("InverseHue", manual_inverse);

	cv::Mat manual_bgr = Run("Hsv2BgrByManual", Hsv2BgrByManual, manual_inverse);
    Show("Hsv2BgrByManual", manual_bgr);

    // OpenCV
    cv::Mat opencv_hsv = Run("Bgr2HsvByCvtcolor", Bgr2HsvByCvtcolor, src);
    Show("Bgr2HsvByCvtcolor", opencv_hsv);

	cv::Mat opencv_inverse = Run("InverseHueForOpenCV", InverseHueForOpenCV, opencv_hsv);
    Show("InverseHueForOpenCV", opencv_inverse);

	cv::Mat opencv_bgr = Run("Hsv2BgrByCvtcolor", Hsv2BgrByCvtcolor, opencv_inverse);
    Show("Hsv2BgrByCvtcolor", opencv_bgr);

    cv::waitKey();
    cv::destroyAllWindows();
    return 0;
}
