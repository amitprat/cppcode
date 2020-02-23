#pragma once
#include <thread>
#include <vector>
#include <iostream>
#include <atomic> 
#include <unordered_set>
#include <cassert>
#include <fstream>
#include <tuple>
#include <queue> 
#include <unordered_map>
#include <string>
#include <sstream>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;

class BinomialCoeff
{
public:
    static void test()
    {
        BinomialCoeff obj;
        vector<pair<int, int>> contexts = {
            {5,2}
        };

        for (auto context : contexts) {
            cout << "Input: " << context.first << ", " << context.second << endl;
            auto res = obj.binomialCoeff(context.first, context.second);
            cout << "Output: " << res << endl;
        }
    }

    int binomialCoeff(int c, int r)
    {
        if (c == r || r == 0) return 1;
        return binomialCoeff(c - 1, r - 1) + binomialCoeff(c - 1, r);
    }
};