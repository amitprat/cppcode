#pragma once

#include <time.h>
#include <stdlib.h>
#include <thread>
#include <vector>
#include <iostream>
#include <atomic>
#include <algorithm>
#include <time.h>
#include <fstream>
#include <tuple>
#include <queue>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

class SortBinaryArr
{
public:
    static void test(vector<int> v)
    {
        SortBinaryArr obj;
        cout << "Input: ";
        for (auto i : v) cout << i << " ";
        cout << "Output: ";
        obj.sort(v);
        for (auto i : v) cout << i << " ";
        cout << endl;
    }

    void sort(vector<int>& v)
    {
        int pos = v.size() - 1;
        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i] != 0) v[pos--] = v[i];
        }
        for (int i = pos; i >= 0; i--) v[i] = 0;
    }
};