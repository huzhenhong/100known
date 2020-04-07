# !usr/bin/python
# -*- coding:utf-8 -*-

"""A differential filter function"""

__author__ = "huzhenhong@2020-04-06"

import cv2 as cv
import numpy as np
from include import tool

@tool.time_cost_calc
def laplacian_filter_maual(src):
    """

    :param src:
    :return:
    """
    kernel = [[0, 1, 0], [1, -4, 1], [0, 1, 0]]

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
def laplacian_filter_opencv(src):
    """

    :param src:
    :return:
    """
    return cv.Laplacian(src, -1, ksize=1)


src = cv.imread('../lena.jpg')
# src = cv.imread('../imori.jpg')
assert src.shape

gray = cv.cvtColor(src, cv.COLOR_BGR2GRAY)

manual = laplacian_filter_maual(gray)

opencv = laplacian_filter_opencv(gray)

tool.cvshow("opencv", np.hstack((gray, manual, opencv)))

cv.waitKey()
cv.destroyAllWindows()
