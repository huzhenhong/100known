# !usr/bin/python
# -*- coding:utf-8 -*-

"""A max-min filter function"""

__author__="huzhenhong@2020-04-04"


import cv2 as cv
import numpy as np
from include import tool


@tool.time_cost_calc
def maxmin_filter_manual(src, k_size=3):
    """

    :param src:
    :param k_size:
    :return:
    """
    h, w = src.shape

    # 边界补零
    padding = k_size // 2
    dst = np.zeros((h + padding * 2, w + padding * 2), dtype=np.float)
    dst[padding: h + padding, padding: w + padding] = src.copy().astype(np.float)

    # 滤波
    for y in range(h):
        for x in range(w):
            max_val = np.max(dst[y: y + k_size, x: x + k_size])
            min_val = np.min(dst[y: y + k_size, x: x + k_size])
            dst[y, x] = max_val - min_val

    # 剪切
    dst = dst[0: h, 0: w]

    return dst.astype(np.uint8)


src = cv.imread('../lena.jpg')
assert src.shape

gray = cv.cvtColor(src, cv.COLOR_BGR2GRAY)

manual = maxmin_filter_manual(gray, 3)
tool.cvshow('maxmin_filter_manual', np.hstack((gray, manual)))


cv.waitKey()
cv.destroyAllWindows()



