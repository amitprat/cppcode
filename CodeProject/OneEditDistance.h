#pragma once
#include <time.h>
#include <stdlib.h>
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

class OneEditDistance
{
public:
    static void test()
    {
        OneEditDistance obj;
        vector <pair<string, string>> contexts =
        { {"geek","geeks"},
        {"cat","cut"},
        {"sunday","unday"},
        { "xyz","xz"},
        {"xyz", "xyk"},
        {"xy", "xyz"},
        {"xyz", "xyz"},
        {"xyz","xzy"},
        {"x", "xyz"}
        };
        for (auto context : contexts)
        {
            cout << "Input:" << context.first << ", " << context.second << endl;
            {
                char different = '\0';
                auto res = obj.isOneEditDistance(context.first, context.second, different);
                cout << "Result:" << res << ", " << different << endl;
            }
            {
                char different = '\0';
                auto res = obj.isOneEditDistance2(context.first, context.second, different);
                cout << "Result:" << res << ", " << different << endl;
            }
        }
    }

    bool isOneEditDistance(string first, string second, char& different)
    {
        different = '$';
        bool flag = false;
        if (first.length() > second.length()) swap(first, second);

        for (int i = 0, j = 0; i < first.length() || j < second.length(); j++)
        {
            if (i == first.length() || first[i] != second[j]) {
                different = second[j];
                if (flag) return false;
                else flag = true;
                if (first.length() == second.length()) i++;
            }
            else { i++; }
        }
        return true;
    }

    bool isOneEditDistance2(string first, string second, char& different)
    {
        different = '$';
        bool flag = false;
        if (first.length() > second.length()) swap(first, second);
        if (second.size() - first.size() > 1) return false;

        int i = 0, j = 0;
        while (i < first.size()) {
            if (first[i] != second[j]) {
                if (flag) break;
                different = second[j];
                j++;
                if (first.length() == second.length()) i++;
                flag = true;
            }
            else i++, j++;
        }
        if (!flag && i + 1 == second.length()) {
            flag = true; different = second[j];
        }
        return flag;
    }
};