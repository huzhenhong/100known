# !usr/bin/python
# -*- coding:utf-8 -*-

"""A average fuction"""

__author__ = "huzhenhong@2020-03-31"

import cv2 as cv
import numpy as np
from include import tool


@tool.time_cost_calc
def average_pooling_mauanl(src, ksize=3):
    """

    :param src:
    :return:
    """
    dst = src.copy()

    h, w, ch = src.shape

    if ksize > h or ksize > w or ksize < 1:
        return dst

    h1 = int(h / ksize)
    w1 = int(w / ksize)

    for y in range(h1):
        for x in range(w1):
            for c in range(ch):
                dst[y*ksize : (y+1)*ksize, x*ksize : (x+1)*ksize, c] \
                    = np.mean(dst[y*ksize : (y+1)*ksize, x*ksize : (x+1)*ksize, c]).astype(np.uint8)

    return dst




src = cv.imread('../test.jpg')
assert src.shape

manual = average_pooling_mauanl(src)
tool.cvshow('average_pooling_mauanl', manual)

cv.waitKey()
cv.destroyAllWindows()

