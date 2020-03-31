# !usr/bin/python
# -*- coding:utf-8 -*-

"""a reduce color function"""

__author__ = "huzhenhong@2020-03-27"


import cv2 as cv
import numpy as np
from include import tool


@tool.time_cost_calc
def reduce_color(src):
    """

    :param src:
    :return:
    """
    dst = np.copy(src)

    dst = dst // 64 * 64 + 32

    return dst


src = cv.imread("../test.jpg")
assert src.shape

dst = reduce_color(src)
tool.cvshow("reduce_color", dst)

cv.waitKey()
cv.destroyAllWindows()

