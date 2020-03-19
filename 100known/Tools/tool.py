# !usr/bin/python
# -*- coding:utf-8 -*-

"""A tools"""

__author__ = "huzhenhong@1020-03-19"

import cv2
from functools import wraps


def time_cost_calc(func):
    """
    性能计算装饰器
    :param func:
    :return:
    """
    @wraps(func)
    def measure_cost_time(*args, **kwargs):
        start = cv2.getCPUTickCount()
        result = func(*args, **kwargs)
        end = cv2.getCPUTickCount()
        cost_time = (end - start) / cv2.getTickFrequency()

        print(f"{func.__name__} cost: {cost_time: .5f} s")
        return result

    return measure_cost_time


def cvshow(name, img):
    """
    opencv显示图片
    :param name:
    :param img:
    :return:
    """
    cv2.namedWindow(name, cv2.WINDOW_NORMAL)
    cv2.imshow(name, img)
