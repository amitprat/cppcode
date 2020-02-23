#pragma once

#include <time.h>
#include <stdlib.h>
#include <thread>
#include <vector>
#include <iostream>
#include <atomic> 
#include <mutex>
using namespace std;

class BinaryArrSort
{
public:
    void tests()
    {
        vector<vector<int>> arrs = {
            {},
            {0},
            {1},
            {0,0},
            {1,1},
            {0,1},
            {0,1,0},
            {1,0,1},
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                        { 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
            { 1, 0, 0, 1, 1, 1, 1, 1, 0, 0 }
        };

        for (auto arr : arrs) {
            cout << "---Given array is--- \n";
            printArray(arr);

            sort(arr);

            cout << "---Rearranged array is--- \n";
            printArray(arr);

            cout << "\n======================\n";
        }
    }

    void sort(vector<int>& a)
    {
        int s = 0, e = a.size() - 1;
        while (s < e) {
            if (a[s] == 0) s++;
            else {
                if (a[e] == 0) swap(a[s], a[e]);
                else e--;
            }
        }
    }

private:
    void printArray(vector<int> a) {
        for (auto i : a) cout << i << " ";
        cout << endl;
    }
};