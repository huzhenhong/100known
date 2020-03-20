# !usr/bin/python
# -*- coding:utf-8 -*-

"""rgb to gray implement by pyhton"""

__author__ = "huzhenhong@2020-03-20"

import cv2 as cv
import numpy as np
from include import tool

# RGB转灰度公式 0.2126 * r + 0.7152 * g + 0.072 * b
@tool.time_cost_calc
def scale_by_manual(src):
    """

    :param src:
    :return:
    """
    dst = 0.2126 * src[:, :, 2] + 0.7152 * src[:, :, 1] + 0.072 * src[:, :, 0]
    return dst.astype(np.uint8)


@tool.time_cost_calc
def scale_by_cvtcolor(src):
    """

    :param src:
    :return:
    """
    return cv.cvtColor(src, cv.COLOR_BGR2GRAY)



src = cv.imread('lena.jpg')
assert src.shape

dst1 = scale_by_manual(src)
tool.cvshow('scale_by_manual', dst1)

dst2 = scale_by_cvtcolor(src)
tool.cvshow('scale_by_cvtcolor', dst2)

cv.waitKey()
cv.destroyAllWindows()


