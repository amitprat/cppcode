#pragma once
#include "../Header.h"

class LongestPalindromicSubsequence {
public:
    static void test() {
        LongestPalindromicSubsequence obj;
        string str = "GEEKS FOR GEEKS";
        obj.lps(str);
    }

    string lps(string seq) {
        int l = lpsDP(seq);
        cout << "LPS: " << l << endl;

        string res = lpsRecStr(seq, 0, seq.length() - 1);
        cout << "LPS string: " << res << ", length=" << res.length() << endl;

        return res;
    }

    int lpsRec(string str, int l, int r) {
        if (l == r) return 1;

        if (str[l] == str[r]) {
            if (l + 1 == r) return 2;
            return 2 + lpsRec(str, l + 1, r - 1);
        }
        else {
            return max(lpsRec(str, l + 1, r), lpsRec(str, l, r - 1));
        }
    }

    string lpsRecStr(string str, int l, int r) {
        if (l == r) return str.substr(l, r - l + 1);

        if (str[l] == str[r]) {
            if (l + 1 == r) return str.substr(l, r - l + 1);
            return str[l] + lpsRecStr(str, l + 1, r - 1) + str[r];
        }
        else {
            string ls = lpsRecStr(str, l + 1, r);
            string rs = lpsRecStr(str, l, r - 1);

            return ls.length() > rs.length() ? ls : rs;
        }
    }

    int lpsDP(string str) {
        int n = str.length();
        vector<vector<int>> memo(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) memo[i][i] = 1;

        for (int p = 2; p <= n; p++) {
            for (int i = 0; i < n - p + 1; i++) {
                int j = i + p - 1;
                if (str[i] == str[j]) {
                    if (p == 2) memo[i][j] = 2;
                    else memo[i][j] = 2 + memo[i + 1][j - 1];
                }
                else {
                    memo[i][j] = max(memo[i + 1][j], memo[i][j - 1]);
                }
            }
        }

        return memo[0][n - 1];
    }
};