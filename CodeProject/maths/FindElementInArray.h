#pragma once
#include "../Header.h"

/*
An array consist of elements whose difference is positive or negative 1. I have to find the given elements without using linear search.
Say
Int arr[]={1,2,3,4,3,4,5,6,7

To find : 6
*/

/*
The answer is skipping. If you're starting at 1, and you're looking for 6, then you know that the best case scenario is the next five values increase by one each. So you skip 5 and check that value. You repeat the same step. It turns out the value at that position is 4. The best case scenario is the next two values increase by one each. So you jump two positions and there's your number.

The key is to figure out at each position how far the goal value is from that position's value and jump ahead by as many steps.
*/
int test()
{
    vector<int> arr = { 1,2,3,4,3,4,5,6,7 };
    int x = 5;

    int s = arr[0];
    int l = x - s;
    int r = arr.size() - 1;
    while (l <= r) {
        if (arr[l] == x) {
            cout << x << " found at index " << l << endl;
            break;
        }
        else {
            l += (x - arr[l]);
        }
    }

    cout << "Element not found!" << endl;

    return 0;
}