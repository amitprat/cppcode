#pragma once

#include <time.h>
#include <stdlib.h>
#include <thread>
#include <vector>
#include <iostream>
#include <atomic> 
#include <algorithm>
#include <time.h>
#include <stack>
#include <tuple>
#include <queue> 
#include <unordered_map>
#include <string>
#include <unordered_set>
using namespace std;

class GenerateNextPrevNumbers
{
public:
    static void test(vector<vector<int>> vals)
    {
        GenerateNextPrevNumbers obj;
        for (auto val : vals) {
            cout << "Input" << " : {";
            for (auto i : val) cout << i << " ";
            cout << "} :: ";

            //auto res = obj.getNext(val);
            //cout << "Next" << " : {";
            //for (auto i : val) cout << i << " ";
            //cout << "}, ";

            auto res = obj.getPrev(val);
            cout << "Prev" << " : {";
            for (auto i : val) cout << i << " ";
            cout << "}" << endl;
        }
    }

    vector<int> getNext(vector<int>& val)
    {
        int sz = val.size() - 1;
        int carry = 0;
        int valToAdd = 1;
        for (int i = sz; i >= 0; i--) {
            int cur = val[i];
            int newVal = cur + carry + valToAdd;
            if (newVal > 9) carry = 1;
            else carry = 0;
            valToAdd = 0;
            val[i] = newVal % 10;
        }
        if (carry) val.insert(val.begin(), carry);

        return val;
    }

    vector<int> getPrev(vector<int>& val)
    {
        int sz = val.size() - 1;
        int borrow = 0;
        int valToSubstract = 1;
        for (int i = sz; i >= 0; i--) {
            int cur = val[i];
            int newVal = cur - borrow - valToSubstract;
            if (newVal < 0) {
                newVal += 10; borrow = 1;
            }
            else borrow = 0;
            valToSubstract = 0;
            val[i] = newVal % 10;
        }
        if (borrow) val[0] += -10;
        if (val[0] == 0) val.erase(val.begin());
        if (val.size() == 0) val.push_back(0);

        return val;
    }
};