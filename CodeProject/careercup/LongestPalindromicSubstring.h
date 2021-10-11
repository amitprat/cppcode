#pragma once
#include "../Header.h"

class LongestPalindromicSubstring {
public:
    static void test() {
        LongestPalindromicSubstring obj;
        string str = "forgeeksskeegfor";
        cout << "\nLength is: " << obj.longestPalSubstr(str);
    }

    string longestPalSubstr(string str) {
        return longestPalSubstrDP(str);
    }

    string longestPalSubstrDP(string str) {
        string longest = "";
        int n = str.length();
        vector<vector<bool>> table(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) table[i][i] = true;
        for (int i = 0; i < n - 1; i++) {
            if (str[i] == str[i + 1]) table[i][i + 1] = true;
        }

        for (int p = 3; p <= n; p++) {
            for (int i = 0; i < n - p + 1; i++) {
                int j = i + p - 1;
                if (str[i] == str[j] && table[i + 1][j - 1]) {
                    if (j - i + 1 > longest.length()) {
                        longest = str.substr(i, j - i + 1);
                    }
                    table[i][j] = true;
                }
            }
        }

        return longest;
    }
};