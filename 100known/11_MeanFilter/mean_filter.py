# !usr/bin/python
# -*- coding:utf-8 -*-

"""A mean filter function"""

__author__="huzhenhong@2020-04-04"


import cv2 as cv
import numpy as np
from include import tool


@tool.time_cost_calc
def mean_filter_manual(src, k_size=3):
    """

    :param src:
    :param k_size:
    :return:
    """
    if len(src.shape) == 2:
        src = np.expand_dims(src, axis=-1)  # 给灰度图增加一个通道

    h, w, c = src.shape

    # 边界补零
    padding = k_size // 2
    dst = np.zeros((h + padding * 2, w + padding * 2, c), dtype=np.float)
    dst[padding: h + padding, padding: w + padding] = src.copy().astype(np.float)

    # 滤波
    for y in range(h):
        for x in range(w):
            for ch in range(c):
                dst[y, x, ch] = np.mean(dst[y: y + k_size, x: x + k_size, ch])

    # 剪切
    dst = dst[: h, : w]

    return dst.astype(np.uint8)


@tool.time_cost_calc
def mean_filter_opencv(src, ksize=3):
    """

    :param src:
    :param ksize:
    :return:
    """
    return cv.blur(src, (ksize, ksize))


src = cv.imread('../lena.jpg')
assert src.shape



manual = mean_filter_manual(src, 3)
tool.cvshow('mean_filter_manual', np.hstack((src, manual)))

opencv = mean_filter_opencv(src, 3)
tool.cvshow('mean_filter_opencv', np.hstack((src, opencv)))

cv.waitKey()
cv.destroyAllWindows()



