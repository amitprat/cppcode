#pragma once
#include "../Header.h"

class LongestCommonSubstringAndSubsequence {
public:
    static void test() {
        {
            string str1 = "AGGTAB";
            string str2 = "GXTXAYB";

            int l1 = longestSubsequence(str1, str1.length(), str2, str2.length());
            int l2 = longestSubsequenceDP(str1, str1.length(), str2, str2.length());

            assert(l1 == l2);

            cout << "Longest subsequence = " << l1 << endl;
        }

        {
            string str1 = "AGGTAB";
            string str2 = "GXTXAYB";

            int l1 = longestSubstring(str1, str1.length(), str2, str2.length(), 0);
            int l2 = longestSubstringDP(str1, str1.length(), str2, str2.length());

            assert(l1 == l2);

            cout << "Longest substring = " << l1 << endl;
        }
    }

    static int longestSubsequence(string a, int n, string b, int m) {
        if (n == 0 || m == 0) return 0;

        if (a[n - 1] == b[m - 1])
            return 1 + longestSubsequence(a, n - 1, b, m - 1);

        return max(longestSubsequence(a, n - 1, b, m), longestSubsequence(a, n, b, m - 1));
    }

    static int longestSubstring(string a, int n, string b, int m, int cnt) {
        if (n == 0 || m == 0) return cnt;

        if (a[n - 1] == b[m - 1])
            return longestSubstring(a, n - 1, b, m - 1, cnt + 1);

        return max(longestSubstring(a, n - 1, b, m, 0), longestSubstring(a, n, b, m - 1, 0));
    }

    static int longestSubsequenceDP(string a, int n, string b, int m) {
        vector<vector<int>> table(n + 1, vector<int>(m + 1));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) table[i][j] = 0;
                else if (a[i - 1] == b[j - 1]) table[i][j] = 1 + table[i - 1][j - 1];
                else table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }

        return table[n][m];
    }

    static int longestSubstringDP(string a, int n, string b, int m) {
        vector<vector<int>> table(n + 1, vector<int>(m + 1));

        int result = 0;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                table[i][j] = 0;
                if (i > 0 && j > 0 && a[i - 1] == b[j - 1]) table[i][j] = 1 + table[i - 1][j - 1];
                result = max(result, table[i][j]);
            }
        }

        return result;
    }
};