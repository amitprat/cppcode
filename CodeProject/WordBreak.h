/**************************************
* Check is word break is possible for a given string and dictionary of words
**************************************/
#pragma once

#include <stdlib.h>
#include <thread>
#include <vector>
#include <iostream>
#include <atomic>
#include <mutex>
#include <time.h>
#include <fstream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <bitset>
#include <string>
#include <functional>
#include <future>
#include "AsyncState.h"
using namespace std;

class WordBreak
{
private:
    unordered_set<string> dict;

public:
    struct Node
    {
        bool flag;
        vector<string> words;
    };
    WordBreak() {
        dict = { "i", "like", "sam", "sung", "samsung", "hello", "am", "a", "m", "t" ,"mobile", "ice","cream", "icecream", "man", "go", "mango","world" };
    }
    static void test()
    {
        WordBreak obj;
        vector<string> strs = { "","i", "ilike", "ilikesamsung", "hellowworld", "iamamit" };
        for (auto str : strs) {
            cout << "Is Word break possible for str = " << str << " : " << obj.wordBreak(str) << endl;
        }
        for (auto str : strs) {
            cout << "Is Word break possible for str = " << str << " : " << obj.wordBreakDP(str) << endl;
        }
        for (auto str : strs) {
            auto res = obj.wordBreakDP1(str);
            cout << "Is Word break possible for str = " << str << " : " << res.flag << endl;
            if (res.flag) {
                for (auto word : res.words) cout << word << " ";
            }
            cout << endl;
        }
    }

    bool wordBreak(string str)
    {
        if (str.empty()) return true;
        for (int i = 1; i <= str.size(); i++) {
            if (dict.find(str.substr(0, i)) != dict.end()) {
                if (wordBreak(str.substr(i))) return true;
            }
        }
        return false;
    }

    bool wordBreakDP(string str)
    {
        int n = str.length();
        bool* table = new bool[n + 1];
        table[0] = true;
        for (int i = 1; i <= n; i++) table[i] = false;

        for (int i = 1; i <= n; i++) {
            if (!table[i]) table[i] = (dict.find(str.substr(0, i)) != dict.end());
            if (table[i]) {
                for (int j = i; j <= n; j++) {
                    if (dict.find(str.substr(i, j - i)) != dict.end()) {
                        table[j] = true;
                    }
                }
            }
        }

        return table[n];
    }

    Node wordBreakDP1(string str)
    {
        int n = str.length();
        Node* table = new Node[n + 1];
        table[0] = { true, {} };
        for (int i = 1; i <= n; i++) table[i] = { false, {} };

        for (int i = 1; i <= n; i++) {
            if (!table[i].flag)
            {
                if ((dict.find(str.substr(0, i)) != dict.end())) {
                    table[i] = { true, {str.substr(0,i)} };
                }
            }
            if (table[i].flag) {
                for (int j = i; j <= n; j++) {
                    if (dict.find(str.substr(i, j - i)) != dict.end()) {
                        vector<string> old = table[i].words;
                        table[j].words.insert(table[j].words.begin(), old.begin(), old.end());
                        table[j].words.push_back(str.substr(i, j - 1));
                        table[j].flag = true;
                    }
                    if (j == n && table[j].flag) return table[j];
                }
            }
        }

        return table[n];
    }
};