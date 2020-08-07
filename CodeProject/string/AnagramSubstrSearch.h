/*
Output:
Processing: {abcde, bcd} : Found substr = bcd at {{1,3}, }
Processing: {aaaaaa, aa} : Found substr = aa at {{0,1}, {1,2}, {2,3}, {3,4}, {4,5}, }
Processing: {abcdefghcde, cde} : Found substr = cde at {{2,4}, {8,10}, }
*/
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
    static void test()
    {
        AnagramSubstrSearch obj;
        vector<pair<string, string>> tests = {
            {"abcde", "bcd"},
            {"aaaaaa", "aa"},
            {"abcdefghcde", "cde"}
        };

        for (auto test : tests) {
            cout << "Processing: {" << test.first << ", " << test.second << "} : ";
            auto res = obj.substringSearch(test.first, test.second);
            cout << "Found substr = " << test.second << " at {";
            for (auto pos : res) cout << "{" << pos.first << "," << pos.second << "}, ";
            cout << "}" << endl;
        }
    }

    vector<pair<int, int>> substringSearch(string txt, string pat)
    {
        vector<pair<int, int>> res;
        int m = pat.length();
        int n = txt.length();
        int patFreq[256] = { 0 };
        int txtFreq[256] = { 0 };

        for (int i = 0; i < m; i++) {
            patFreq[pat[i]]++;
            txtFreq[txt[i]]++;
        }

        for (int i = m; i <= n; i++) {
            if (match(patFreq, txtFreq)) res.push_back({ i - m, i - 1 });
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