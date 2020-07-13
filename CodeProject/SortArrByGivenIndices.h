#pragma once

#include <time.h>
#include <stdlib.h>
#include <thread>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <time.h>
#include <stack>
#include <tuple>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <fstream>
using namespace std;

class SortArrByGivenIndices
{
    static void test()
    {
        SortArrByGivenIndices obj;
        vector<int> a = {};
        vector<int> order = {};
        obj.sortArray(a, order);

        cout << "Sorted Array: ";
        for (auto i : a) cout << i << " ";
        cout << endl;
    }

    void sortArray(vector<int>& a, vector<int> order)
    {
        sort(a.begin(), a.end(), [order]() {});
    }
};