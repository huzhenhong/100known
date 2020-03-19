# !usr/bin/python
# -*- coding:utf-8 -*-

"""A switch channel function implement by python"""

__author__ = "huzhenhong@1020-03-19"

import cv2
import numpy as np
from Tools import tool


@tool.time_cost_calc
def switch_by_manual(src):
    """
    交换第一和第三通道
    :param src:
    :return:
    """
    dst = np.zeros_like(src)
    dst[:, :, 0] = src[:, :, 2]
    dst[:, :, 1] = src[:, :, 1]
    dst[:, :, 2] = src[:, :, 0]

    return dst


@tool.time_cost_calc
def switch_by_split_and_merge(src):
    """

    :param src:
    :return:
    """
    channels = cv2.split(src)
    channels[0], channels[2] = channels[2], channels[0]
    dst = cv2.merge(channels)

    return dst


@tool.time_cost_calc
def switch_by_mixChannels(src):
    """

    :param src:
    :return:
    """
    dst = np.zeros_like(src)

    cv2.mixChannels([src], [dst], fromTo=[0, 2, 1, 1, 2, 0])

    return dst

src = cv2.imread("lena.jpg")

dst1 = switch_by_manual(src)
tool.cvshow("switch_by_manual", np.hstack((src, dst1)))

dst2 = switch_by_split_and_merge(src)
tool.cvshow("switch_by_split_and_merge", np.hstack((src, dst2)))

dst3 = switch_by_mixChannels(src)
tool.cvshow("switch_by_mixChannels", np.hstack((src, dst3)))

while True:
    if 27 == cv2.waitKey():
        break
cv2.destroyAllWindows()
