#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

def print_array(array):
    print("__name__", __name__)
    for i in range(0, len(array)):
        print(array[i], end=' ')
    print();

def insert_sort(nums):
    sz = len(nums);
    for i in range(1, sz - 1):
        key = nums[i];
        #insert key to nums[0..sz-2]
        j = i - 1
        while (j >= 0 and key > nums[j]):
            nums[j + 1] = nums[j]
            j -= 1
        nums[j+1] = key;
    print_array(nums)

def main():
    nums = [ 3, 2, 5, 6, 4, 1];
    insert_sort(nums);

if __name__ == "__main__":
    main()
