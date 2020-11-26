#pragma once

#include <time.h>
#include <stdlib.h>
#include <thread>
#include <vector>
#include <iostream>
#include <atomic>
#include <mutex>
#include <time.h>
#include <fstream>
#include <tuple>
#include <queue>
#include <unordered_map>
#include <string>
#include <json/json.h>
using namespace std;

class SubsetSum
{
public:
    static void test()
    {
        SubsetSum obj;
        int a[] = { 2,9 };
        int k = 3, n = 9;
        auto res = obj.findSubsetSum(a, k, n, sizeof(a) / sizeof(int));

        stringstream ss;
        for (auto i : res) {
            ss << "{";
            for (auto j : i) {
                ss << j << ", ";
            }
            ss << "}, ";
        }
        cout << "Res =" << ss.str() << endl;

        obj.findSubsetSumDP(a, k, n, sizeof(a) / sizeof(int));
    }

    vector<vector<int>> findSubsetSum(int a[], int size, int sum, int n)
    {
        vector<vector<int>> subsets;
        findSubsetSum(a, size, sum, n, subsets);

        return subsets;
    }

    vector<vector<int>> findSubsetSumDP(int a[], int size, int sum, int n)
    {
        vector<vector<int>> subsets;
        bool* table = new bool[sum + 1];
        memset(table, false, (sum + 1) * sizeof(bool));
        table[0] = true;

        for (int i = 0; i < n; i++) {
            for (int s = a[i]; s < sum + 1; s++) {
                table[s] |= table[s - a[i]];
            }
        }
        for (auto i = 0; i < sum + 1; i++) cout << (bool)table[i] << " ";
        cout << endl;
        return subsets;
    }

private:
    void findSubsetSum(int a[], int size, int sum, int n, vector<vector<int>>& subsets, vector<int> curset = {})
    {
        if (size == 0 && sum == 0) { subsets.push_back(curset); }
        if (size == 0 || n <= 0) return;
        findSubsetSum(a, size, sum, n - 1, subsets, curset);
        curset.push_back(a[n - 1]);
        findSubsetSum(a, size - 1, sum - a[n - 1], n - 1, subsets, curset);
        curset.pop_back();
    }
};