#!/usr/bin/env python
# coding: utf-8


def brute():
    first = 1
    second = 2
    total = 2
    while True:
        sum = first + second
        first = second
        second = sum
        if second >= 4E6:
            break
        if sum % 2 == 0:
            total += sum
            print '=== %f' % sum
    print ' Total : %f ' % total

if __name__ == "__main__":
    brute()
