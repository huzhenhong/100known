# !usr/bin/python
# -*- coding:utf-8 -*-

"A threshding demo implement bu python"

__author__ = "huzhenhong@2020-03-20"


import cv2 as cv
import numpy as np
from include import tool


@tool.time_cost_calc
def thresholding_by_manual(src):
    """

    :param src:
    :return:
    """
    dst = np.zeros_like(src)
    dst[src > 128] = 255

    return dst


@tool.time_cost_calc
def thresholding_by_threshold(src):
    """

    :param src:
    :return:
    """
    thresh, dst = cv.threshold(src, 128, 255, cv.THRESH_BINARY)
    return dst

src = cv.imread("lena.jpg")
assert src.shape

gray = cv.cvtColor(src, cv.COLOR_BGR2GRAY)

dst1 = thresholding_by_manual(gray)
tool.cvshow("thresholding_by_manual", dst1)

dst2 = thresholding_by_threshold(gray)
tool.cvshow("thresholding_by_threshold", dst2)

cv.waitKey()
cv.destroyAllWindows()

