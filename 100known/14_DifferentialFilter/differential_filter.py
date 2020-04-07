# !usr/bin/python
# -*- coding:utf-8 -*-

"""A differential filter function"""

__author__ = "huzhenhong@2020-04-06"

import cv2 as cv
import numpy as np
from include import tool

@tool.time_cost_calc
def differential_filter(src, b_horizontial=False):
    """

    :param src:
    :param b_horizontial:
    :return:
    """
    if b_horizontial:
        kernel = [[0, -1, 0], [0, 1, 0], [0, 0, 0]]
    else:
        kernel = [[0, 0, 0], [-1, 1, 0], [0, 0, 0]]

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




src = cv.imread('../lena.jpg')
assert src.shape

gray = cv.cvtColor(src, cv.COLOR_BGR2GRAY)

vertical = differential_filter(gray)
horizontial = differential_filter(gray, True)
tool.cvshow("manual", np.hstack((gray, vertical, horizontial)))

cv.waitKey()
cv.destroyAllWindows()
