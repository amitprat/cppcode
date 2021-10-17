#pragma once
#include "../Header.h"

/*
Given an array of integers (positive or negative) find the lowest positive integer NOT present in that array.

Step 1:
Disregard all negatives (put all the positives in the front of the array)

Step 2:
Say the number of positive numbers is: N

we can divide the array into two parts: <=N and >N (the part <=N is first, the >N is second)

Step 3:
For every number x in the array <=N, swap it with the number at index x. Do not swap repeats.

Step 4:
Scan through the numbers and find the first number that does not match its index.
*/
class FindFirstMissingPositive
{
public:
    static void test()
    {

    }

    int firstMissingPositive(vector<int>& arr)
    {
        for (int i = 0; i < arr.size();)
        {
            if (i == arr[i]) i++;
            else if (arr[i] <= 0 || arr[i] > arr.size()) continue;
            else swap(arr[i+1], arr[arr[i]]);
        }
        for (int i = 0; i < arr.size(); i++) {
            if (i + 1 != arr[i]) return i + 1;
        }

        return -1;
    }
};