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
using namespace std;

class CheckAnagramOfString
{
public:
    static void test()
    {
        CheckAnagramOfString obj;
        vector<pair<string, string>> inputs = {
            {"xyz", "afdgzyxksldfm"}
        };
        for (auto input : inputs) {
            obj.findAnagram(input.first, input.second);
        }
    }

    string findAnagram(string pat, string txt)
    {
        int i = 0, j = 0;
        int cnt = 0;
        int patCnt[128] = { 0 };
        int txtCnt[128] = { 0 };
        int n = txt.size(), m = pat.size();

        for (; i < m && j <n; i++, j++) {
            patCnt[pat[i]]++;
            txtCnt[txt[j]]++;
            if (patCnt[pat[i]] && patCnt[pat[i]] <= txtCnt[txt[j]]) cnt++;
        }
        if (cnt == m) return txt.substr(j - m, m);
        for (; j < n; j++) {
            txtCnt[txt[j]]++;
            if (patCnt[txt[j]] && patCnt[txt[j]] <= txtCnt[txt[j]]) cnt++;

            txtCnt[txt[j-m]]--;
            if (patCnt[txt[j-m]] && patCnt[txt[j-m]] <= txtCnt[txt[j-m]]) cnt--;

            if (cnt == m) return txt.substr(j - m, m);
        }

        return string();
    }
};