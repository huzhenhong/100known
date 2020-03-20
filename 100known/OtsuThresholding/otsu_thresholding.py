# !usr/bin/python
# -*- coding:utf-8 -*-

"""A otsu thresholding implement by python"""

__author__ = "huzhenhong@2020-03-20"


import cv2 as cv
import numpy as np
from include import tool

@tool.time_cost_calc
def otsu_thresholding_by_manual(src):
    """

    :param src:
    :return:
    """
    dst = np.zeros_like(src)

    max_variance = 0.0
    best_thresh = 0

    for thresh in range(0, 255):
        overtop = src[src > thresh]
        under = src[src <= thresh]

        p0 = 1.0 * len(overtop) / src.size
        p1 = 1 - p0

        x0 = 0.0
        if len(overtop):
            x0 = np.sum(overtop).astype(np.float) / len(overtop)
        x1 = 0.0
        if len(under):
            x1 = np.sum(under).astype(np.float) / len(under)

        variance = 2 * p0 * p1 * np.power(x0 - x1, 2)
        if variance > max_variance:
            max_variance = variance
            best_thresh = thresh

    dst[src > best_thresh] = 255

    return dst


@tool.time_cost_calc
def otsu_thresholding_by_threshold(src):
    """

    :param src:
    :return:
    """
    _, dst = cv.threshold(src, 0, 255, cv.THRESH_OTSU)
    return dst


src = cv.imread("lena.jpg")
assert src.shape

gray = cv.cvtColor(src, cv.COLOR_BGR2GRAY)

dst1 = otsu_thresholding_by_manual(gray)
tool.cvshow("otsu_thresholding_by_manual", np.hstack((gray, dst1)))

dst2 = otsu_thresholding_by_threshold(gray)
tool.cvshow("otsu_thresholding_by_threshold", np.hstack((gray, dst2)))

cv.waitKey()
cv.destroyAllWindows()