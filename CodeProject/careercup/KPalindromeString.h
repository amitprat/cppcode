#pragma once
#include "../Header.h"

class KPalindromeString {
public:
    static void test() {
        KPalindromeString obj;

        string input1 = "abxa";
        int k1 = 1;
        cout << obj.isKPalindromeString(input1, k1) << endl;

        string input2 = "abdxa";
        int k2 = 1;
        cout << obj.isKPalindromeString(input2, k2) << endl;
    }

    bool isKPalindromeString(string str, int k) {
        return isKPalindromeStringOriginal(str, k);
    }

    bool isKPalindromeStringOriginal(string str, int k) {
        int n = str.length();
        vector<vector<int>> table(n + 1, vector<int>(n + 1));
        string revstr = str;
        reverse(revstr.begin(), revstr.end());

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 && j == 0) table[i][j] = 0;
                else if (i == 0) table[i][j] = j; // insert
                else if (j == 0) table[i][j] = i; // delete
                else {
                    if (str[i - 1] == revstr[j - 1]) {// char match
                        table[i][j] = table[i - 1][j - 1];
                    }
                    else {
                        // no replace, only insert and delete
                        table[i][j] = 1 + min(table[i - 1][j], table[i][j - 1]);
                    }
                }
            }
        }

        int minDist = table[n][n];
        cout << "Min Distance: " << minDist << ", and k: " << k << " for string: " << str << endl;

        return minDist <= 2 * k;
    }

    bool isKPalindromeStringOptimized(string str, int k) {
        int n = str.length();
        vector<vector<int>> table(n + 1, vector<int>(n + 1, INT_MAX));
        string revstr = str;
        reverse(revstr.begin(), revstr.end());

        for (int i = 0; i <= n; i++) {
            int from = max(0, i - k);
            int to = min(n, i + k);
            for (int j = from; j <= to; j++) {
                if (i == 0 && j == 0) table[i][j] = 0;
                else if (i == 0) table[i][j] = j; // insert
                else if (j == 0) table[i][j] = i; // delete
                else {
                    if (str[i - 1] == revstr[j - 1]) {// char match
                        table[i][j] = table[i - 1][j - 1];
                    }
                    else {
                        // no replace, only insert and delete
                        table[i][j] = 1 + min(table[i - 1][j], table[i][j - 1]);
                    }
                }
            }
        }

        int minDist = table[n][n];
        cout << "Min Distance: " << minDist << ", and k: " << k << " for string: " << str << endl;

        return minDist <= 2 * k;
    }
};