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
#include <map>
using namespace std;

class PatternMatch
{
public:
    static void test()
    {
        PatternMatch obj;
        vector<pair<string, string>> inputs = {
            {"abba", "redbluebluered"},
            {"aaaa", "asdasdasdasd"},
            {"aabb","xyzabcxyzabc"},
            {"abc", "redbluebluered"},
            {"acbae", "redbluegreenredyellow"},
            {"abcdefghijabcd","abcdefghijabcd"}
        };
        for (auto input : inputs) {
            auto res = obj.isMatch(input.first, input.second);
            cout << input.first << " ~=" << input.second << " : " << res << endl;
        }
    }

    bool isMatch(string pattern, string text)
    {
        int i = 0, j = 0;
        unordered_map<char, string> map;
        return isMatch(map, i, j, pattern, text);
    }

    bool isMatch(unordered_map<char, string>& map, int i, int j, string pat, string txt)
    {
        if (i == pat.size() && j == txt.size()) {
            for (auto m : map) {
                cout << m.first << " " << m.second << endl;
            }
            return true;
        }
        if (i == pat.size() || j == txt.size()) return false;

        if (map.find(pat[i]) != map.end()) {
            string toMatch = map[pat[i]];
            string txtToMatch = txt.substr(j, toMatch.length());
            if (toMatch != txtToMatch) return false;
            return isMatch(map, i + 1, j += txtToMatch.length(), pat, txt);
        }
        else {
            for (int k = j; k < txt.length(); k++) {
                string txtToMatch = txt.substr(j, k - j + 1);
                map[pat[i]] = txtToMatch;
                if (isMatch(map, i + 1, j + txtToMatch.length(), pat, txt)) return true;
                map.erase(pat[i]);
            }
        }

        return false;
    }
};