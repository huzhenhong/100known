# !usr/bin/python
# -*- coding:utf-8 -*-

"""A differential filter function"""

__author__ = "huzhenhong@2020-04-06"

import cv2 as cv
import numpy as np
from include import tool

@tool.time_cost_calc
def emboss_filter_maual(src):
    """

    :param src:
    :return:
    """
    kernel = [[-2, -1, 0], [-1, 1, 1], [0, 1, 2]]

    h, w = src.shape
    # padding
    dst = np.zeros((h + 2, w + 2), dtype=np.float)
    dst[1: 1+h, 1: 1+w] = src.copy().astype(np.float)

    for y in range(h):
        for x in range(w):

            dst[y][x] = np.sum(kernel * dst[y: y+3, x: x+3])

    dst = dst[:h, :w]
    dst = np.clip(dst, 0, 255).astype(np.uint8)

    return dst


@tool.time_cost_calc
def emboss_filter_opencv(src):
    """

    :param src:
    :return:
    """
    kernel = np.array([[-2, -1, 0], [-1, 1, 1], [0, 1, 2]])

    return cv.filter2D(src, -1, kernel)


src = cv.imread('../lena.jpg')
# src = cv.imread('../imori.jpg')
assert src.shape

gray = cv.cvtColor(src, cv.COLOR_BGR2GRAY)

manual = emboss_filter_maual(gray)

opencv = emboss_filter_opencv(gray)

tool.cvshow("opencv", np.hstack((gray, manual, opencv)))

cv.waitKey()
cv.destroyAllWindows()
