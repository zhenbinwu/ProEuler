#!/usr/bin/env python
# coding: utf-8

import time


def print_timing(func):
    def wrapper(*arg):
        t1 = time.time()
        res = func(*arg)
        t2 = time.time()
        print '%s took %0.3f ms ' % (func.func_name, (t2 - t1) * 1000.0)
        return res
    return wrapper


@print_timing
def simple():
    sum = 0
    for i in range(1, 1000):
        if i % 3 == 0 or i % 5 == 0:
            sum += i
    print sum


@print_timing
def best():
    max = 999
    top3 = max / 3
    print top3
    top5 = max / 5
    print top5
    total3 = 3 * (1 + top3) * (top3 / 2.0)
    total5 = 5 * (1 + top5) * (top5 / 2.0)
    print total3 + total5

    #subtract the double counting 15
    top15 = max / 15
    total15 = 15 * (1 + top15) * (top15 / 2.0)
    print total3 + total5 - total15


if __name__ == "__main__":
    simple()
    best()
