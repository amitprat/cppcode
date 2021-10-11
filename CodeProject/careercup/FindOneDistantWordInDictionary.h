#pragma once
#include "../Header.h"

class FindOneDistantWordInDictionary {
public:
    static void test() {
        unordered_set<string> words = { "ab","aapplx","apple", "pineapple", "banana", "orange" };
        string word = "a";

        auto res = findWord(words, word);
        cout << res << endl;
    }

    static string findWord(unordered_set<string>& words, string target) {
        for (auto word : words) {
            if (isOneDistant(word, target)) return word;
        }

        return "";
    }

    static bool isOneDistant(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        if (abs(n - m) > 1) return false;
        bool diff = false;

        for (int i = 0, j = 0; i < n || j < m; i++, j++) {
            if (i == n || j == m || word1[i] != word2[j]) {
                if (diff) return false;
                diff = true;
                if (n < m) i--;
                else if (n > m) j--;
            }
        }

        return diff;
    }
};