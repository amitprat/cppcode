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
#include <unordered_set>
using namespace std;

class MakeCommonArr
{
public:
    static void test(vector<int> v1, vector<int> v2, vector<int> v3)
    {
        MakeCommonArr obj;
        cout << "Output: ";
        auto res = obj.findCommond(v1, v2, v3);
        for (auto i : res) cout << i << " ";
        cout << endl;
    }

    vector<int> findCommond(vector<int> v1, vector<int> v2, vector<int> v3)
    {
        vector<int> res;
        unordered_map<int, unordered_set<int>> m;
        for (auto i : v1) m[i].insert(0);
        for (auto i : v2) m[i].insert(1);
        for (auto i : v3) m[i].insert(2);

        for (auto i : m) {
            if (i.second.size() > 1) res.push_back(i.first);
        }

        return res;
    }
};