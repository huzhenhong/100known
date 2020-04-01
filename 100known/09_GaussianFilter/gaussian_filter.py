# !usr/bin/python
# -*- coding:utf-8 -*-

"""A gaussian filter function"""

__author__="huzhenhong@2020-04-01"


import cv2 as cv
import numpy as np
from include import tool


@tool.time_cost_calc
def gaussian_filter_manual(src, k_size=3, sigma=1.0):
    """

    :param src:
    :param k_size:
    :param sigma:
    :return:
    """
    if len(src.shape) == 2:
        src = np.expand_dims(src, axis=-1)  # 给灰度图增加一个通道

    h, w, c = src.shape

    # 边界补零
    padding = k_size // 2
    dst = np.zeros((h + padding * 2, w + padding * 2, c), dtype=np.float)
    dst[padding: h + padding, padding: w + padding] = src.copy().astype(np.float)

    # 生产高斯核
    kernel = np.zeros((k_size, k_size), dtype=np.float)
    for y in range(-padding, -padding + k_size):
        for x in range(-padding, -padding + k_size):
            kernel[y + padding, x + padding] = 1 / (2*np.pi*(sigma**2)) * np.exp(-(x**2 + y**2)/(2*(sigma**2)))

    kernel /= kernel.sum()

    # 滤波
    for y in range(h):
        for x in range(w):
            for ch in range(c):
                dst[y + padding, x + padding, ch] = np.sum(kernel * dst[y: y + k_size, x: x + k_size, ch])

    # 剪切
    dst = dst[padding: padding + h, padding: padding + w]
    # 像素之可能大于255
    dst = np.clip(dst, 0, 255)

    return dst.astype(np.uint8)


@tool.time_cost_calc
def gaussian_filter_opencv(src, ksize=3, sigma=1.0):
    """

    :param src:
    :param ksize:
    :param sigma:
    :return:
    """
    return cv.GaussianBlur(src, (ksize, ksize), sigma)


src = cv.imread('../test.jpg')
assert src.shape

manual = gaussian_filter_manual(src, 3, 1.3)
tool.cvshow('gaussian_filter_manual', np.hstack((src, manual)))

opencv = gaussian_filter_opencv(src, 3, 1.3)
tool.cvshow('gaussian_filter_opencv', np.hstack((src, opencv)))

cv.waitKey()
cv.destroyAllWindows()



