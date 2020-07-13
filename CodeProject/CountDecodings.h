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

class CountDecodings
{
public:
    static void test()
    {
        string str = "1123";
        CountDecodings obj;
        unordered_set<string> col;
        cout << obj.count(str, 0, col, "") << endl;
        for (auto s : col) cout << s << " ";
        cout << endl;
    }

    int count(string str, int index, unordered_set<string>& col, string prefix)
    {
        if (index == str.size()) {
            col.insert(prefix);
            return 1;
        }
        if (str[index] == '0') return 0;

        int res = count(str, index + 1, col, prefix + string(1, str[index] + 'a' - '1'));
        if (index + 1 < str.size()) {
            if (str[index] == '1') {
                res += count(str, index + 2, col, prefix + string(1, 10 + str[index + 1] + 'a' - '1'));
            }
            if (str[index] == '2' && str[index + 1] <= '6') {
                res += count(str, index + 2, col, prefix + string(1, 20 + str[index + 1] + 'a' - '1'));
            }
        }

        return res;
    }
};