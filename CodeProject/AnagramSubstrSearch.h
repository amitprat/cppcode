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
using namespace std;

class AnagramSubstrSearch
{
public:
    void test()
    {
        vector<pair<string, string>> v = {
            {"abcde", "bcd"},
            {"aaaaaa", "aa"},
            {"abcdefghcde", "cde"}
        };

        for (auto i : v) {
            cout << "Processing: {" << i.first << ", " << i.second << "} : ";
            auto res = substringSearch(i.first, i.second);
            cout << "Found substr = {";
            for (auto j : res) cout << j << " ";
            cout << "}" << endl;
        }
    }

    vector<string> substringSearch(string txt, string pat)
    {
        vector<string> res;
        int m = pat.length();
        int n = txt.length();
        int patFreq[256] = { 0 };
        int txtFreq[256] = { 0 };

        for (int i = 0; i < m; i++) {
            patFreq[pat[i]]++;
            txtFreq[txt[i]]++;
        }

        for (int i = m; i <= n; i++) {
            if (match(patFreq, txtFreq)) res.push_back(txt.substr(i - m, m));
            txtFreq[txt[i - m]]--;
            if (i < n) txtFreq[txt[i]]++;
        }

        return res;
    }

    bool match(int patFreq[], int txtFreq[])
    {
        for (int i = 0; i < 256; i++) if (txtFreq[i] != patFreq[i]) return false;
        return true;
    }
};