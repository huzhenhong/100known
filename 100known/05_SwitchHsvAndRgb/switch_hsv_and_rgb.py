# !usr/bin/python
# -*- coding:utf-8 -*-

"""A switch channel function implement by python"""

__author__ = "huzhenhong@1020-03-25"

import cv2
import numpy as np
from include import tool


@tool.time_cost_calc
def bgr2hsv_by_manual(src):
    """

    :param src:
    :return:
    """
    src = src / 255.0
    dst = np.zeros_like(src)

    # 获取每个像素点三个通道中的最大值和最小值
    max_v = np.max(src, axis=2)
    min_v = np.min(src, axis=2)

    # 获取每个像素点三个通道中最小值的索引
    min_index = np.argmin(src, axis=2)

    # H色相
    # min == max
    dst[..., 0][np.where(max_v == min_v)] = 0

    # min == B
    index_0 = np.where(min_index == 0)
    dst[..., 0][index_0] = 60 * (src[..., 1][index_0] - src[..., 2][index_0]) / (max_v[index_0] - min_v[index_0]) + 60

    # min == G
    index_1 = np.where(min_index == 1)
    dst[..., 0][index_1] = 60 * (src[..., 2][index_1] - src[..., 0][index_1]) / (max_v[index_1] - min_v[index_1]) + 300

    # min == R
    index_2 = np.where(min_index == 2)
    dst[..., 0][index_2] = 60 * (src[..., 0][index_2] - src[..., 1][index_2]) / (max_v[index_2] - min_v[index_2]) + 180

    # S饱和度
    dst[..., 1] = max_v - min_v

    # V明度
    dst[..., 2] = max_v

    return dst


@tool.time_cost_calc
def inverse_hue_by_manual(src):
    """

    :param src:
    :return:
    """
    dst = src.copy()
    tmp = (src[..., 0] + 180) % 360
    dst[..., 0] = tmp
    return dst


@tool.time_cost_calc
def hsv2bgr_by_manual(src):
    """

    :param src:
    :return:
    """
    h, s, v = src[..., 0], src[..., 1], src[..., 2]
    c = s
    h1 = h / 60
    x = c * (1 - abs(h1 % 2 - 1))
    z = np.zeros_like(h)

    dst = np.zeros_like(src)

    vals = [[c, x, z], [x, c, z], [z, c, x], [z, x, c], [x, z, c], [c, z, x]]

    for i in range(6):
        index = np.where((i <= h1) & (h1 < i + 1))  # h1是单通道图像，不是标量
        dst[..., 2][index] = (v - c)[index] + vals[i][0][index]    # b
        dst[..., 1][index] = (v - c)[index] + vals[i][1][index]    # g
        dst[..., 0][index] = (v - c)[index] + vals[i][2][index]    # r

    return dst

@tool.time_cost_calc
def bgr2hsv_by_cvtcolor(src):
    """

    :param src:
    :return:
    """
    return cv2.cvtColor(src, cv2.COLOR_BGR2HSV)


@tool.time_cost_calc
def inverse_hue_for_opencv(src):
    """

    :param src:
    :return:
    """
    dst = src.astype(np.uint16)

    # dst[..., 0] = ((dst[..., 0].astype(np.uint16) + 90) % 180).astype(np.uint8)
    dst[..., 0] = (dst[..., 0] + 90) % 180

    return dst.astype(np.uint8)


@tool.time_cost_calc
def hsv2bgr_by_cvtcolor(src):
    """

    :param src:
    :return:
    """
    return cv2.cvtColor(src, cv2.COLOR_HSV2BGR)


src = cv2.imread("../test.jpg", cv2.IMREAD_COLOR)
assert src.shape

hsv_manual = bgr2hsv_by_manual(src)
tool.cvshow("bgr2hsv_by_manual", hsv_manual)

inverse_hue = inverse_hue_by_manual(hsv_manual)
tool.cvshow("inverse_hue_by_manual", inverse_hue)

bgr_manual = hsv2bgr_by_manual(inverse_hue)
tool.cvshow("hsv2bgr_by_manual", bgr_manual)

##################################

hsv_opencv = bgr2hsv_by_cvtcolor(src)
tool.cvshow("bgr2hsv_by_cvtcolor", hsv_opencv)

inverse_hue_opencv = inverse_hue_for_opencv(hsv_opencv)
tool.cvshow("inverse_hue_for_opencv", inverse_hue_opencv)

bgr_opencv = hsv2bgr_by_cvtcolor(inverse_hue_opencv)
tool.cvshow("hsv2bgr_by_cvtcolor", bgr_opencv)


while True:
    if 27 == cv2.waitKey():
        break
cv2.destroyAllWindows()
