#pragma once

#include <time.h>
#include <stdlib.h>
#include <thread>
#include <vector>
#include <iostream>
#include <atomic> 
#include <mutex>
using namespace std;

class ArrangeNumbers
{
public:
    void test()
    {
        int arr[] = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 };
        int n = sizeof(arr) / sizeof(arr[0]);

        cout << "Given array is \n";
        printArray(arr, n);

        arrange(arr, n);

        cout << "Rearranged array is \n";
        printArray(arr, n);
    }

    void arrange(int a[], int n)
    {
        int outOfIndex = -1;
        for (int i = 0; i < n; i++) {
            if (outOfIndex != -1) {
                if (rightElement(a[outOfIndex], a[i])) {
                    rightRotate(a, outOfIndex, i);
                    if (i - outOfIndex >= 2) outOfIndex += 2;
                    else outOfIndex = -1;
                }
            }

            if (outOfIndex == -1 && outOfPos(i, a[i])) {
                outOfIndex = i;
            }
        }
    }

private:
    bool rightElement(int ol, int cur) {
        return (ol >= 0 && cur < 0) || (ol < 0 && cur >= 0);
    }

    bool outOfPos(int i, int elem) {
        return (elem >= 0 && i & 1) || (elem < 0 && !(i && 1));
    }

    void rightRotate(int a[], int s, int e)
    {
        int tmp = a[e];
        for (int i = e; i > s; i--) { a[i] = a[i - 1]; }
        a[s] = tmp;
    }

    void printArray(int a[], int n) {
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }
};