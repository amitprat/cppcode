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
#include <sstream> 
#include <unordered_map>
#include <unordered_set>
using namespace std;

class LongestUniqueSubstr
{
public:
    static void test()
    {
        LongestUniqueSubstr obj;
        vector<string> strs = { "", "a","abcabcbb", "bbbbb", "pwwkew" };
        for (auto str : strs) {
            cout << obj.longest(str) << endl;
        }
    }

    string longest(string str)
    {
        unordered_map<char, int> m;
        string res = string(1, str[0]);
        for (int i = 0; i < str.size(); i++) {
            if (m.find(str[i]) != m.end()) {
                int s = m[str[i]]
                    ;
                if (i - s > res.size()) {
                    res = str.substr(s, i - s);
                }
            }
            m[str[i]] = i;
        }

        return res;
    }
};