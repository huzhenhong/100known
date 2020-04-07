# !usr/bin/python
# -*- coding:utf-8 -*-

"""A differential filter function"""

__author__ = "huzhenhong@2020-04-06"

import cv2 as cv
import numpy as np
from include import tool

@tool.time_cost_calc
def prewitt_filter_maual(src, b_horizontial=False):
    """

    :param src:
    :param b_horizontial:
    :return:
    """
    if b_horizontial:
        kernel = [[1, 0, -1], [1, 0, -1], [1, 0, -1]]
    else:
        kernel = [[1, 1, 1], [0, 0, 0], [-1, -1, -1]]

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
def prewitt_filter_opencv(src, b_horizontial=False):
    """

    :param src:
    :param b_horizontial:
    :return:
    """
    if b_horizontial:
        kernel =np.array([[1, 0, -1], [1, 0, -1], [1, 0, -1]])
    else:
        kernel = np.array([[1, 1, 1], [0, 0, 0], [-1, -1, -1]])

    return cv.filter2D(src, -1, kernel)


src = cv.imread('../lena.jpg')
assert src.shape

gray = cv.cvtColor(src, cv.COLOR_BGR2GRAY)

vertical_manual = prewitt_filter_maual(gray)
horizontial_manual = prewitt_filter_maual(gray, True)
tool.cvshow("manual", np.hstack((gray, vertical_manual, horizontial_manual)))

vertical_opencv = prewitt_filter_opencv(gray)
horizontial_opencv = prewitt_filter_opencv(gray, True)
tool.cvshow("opencv", np.hstack((gray, vertical_opencv, horizontial_opencv)))

cv.waitKey()
cv.destroyAllWindows()
