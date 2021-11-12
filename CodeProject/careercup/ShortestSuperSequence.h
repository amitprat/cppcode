#pragma once
#include "../Header.h"

// https://www.geeksforgeeks.org/shortest-common-supersequence/
class ShortestSuperSequence {
public:
    static void test() {
        string X = "AGGTB";
        string Y = "GXTXAYB";

        int l1 = shortestSuperSequenceUsingLCS(X, Y);
        int l2 = shortestSuperSequence(X, Y);

        assert(l1 == l2);

        cout << "Shortest sequence length = " << l1 << endl;
    }

    static int shortestSuperSequenceUsingLCS(string a, string b) {
        int l1 = lcs(a, b, a.length(), b.length());
        int l2 = lcsDP(a, b, a.length(), b.length());

        assert(l1 == l2);

        return (a.length() + b.length() - l1);
    }

    static int shortestSuperSequence(string a, string b) {
        int l1 = shortestSuperSequenceRec(a, b, a.length(), b.length());
        int l2 = shortestSuperSequenceDP(a, b, a.length(), b.length());

        assert(l1 == l2);

        return l1;
    }

    static int shortestSuperSequenceRec(string a, string b, int n, int m) {
        if (n == 0) return m;
        if (m == 0) return n;

        if (a[n - 1] == b[m - 1]) return 1 + shortestSuperSequenceRec(a, b, n - 1, m - 1);

        return 1 + min(shortestSuperSequenceRec(a, b, n - 1, m), shortestSuperSequenceRec(a, b, n, m - 1));
    }

    static int shortestSuperSequenceDP(string a, string b, int n, int m) {
        vector<vector<int>> memo(n + 1, vector<int>(m + 1));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0) memo[i][j] = j;
                else if (j == 0) memo[i][j] = i;
                else if (a[i - 1] == b[j - 1]) memo[i][j] = 1 + memo[i - 1][j - 1];
                else memo[i][j] = 1 + min(memo[i - 1][j], memo[i][j - 1]);
            }
        }

        return memo[n][m];
    }

    static int lcs(string a, string b, int n, int m) {
        if (n == 0 || m == 0) return 0;

        if (a[n - 1] == b[m - 1]) return 1 + lcs(a, b, n - 1, m - 1);

        return max(lcs(a, b, n - 1, m), lcs(a, b, n, m - 1));
    }

    static int lcsDP(string a, string b, int n, int m) {
        vector<vector<int>> memo(n + 1, vector<int>(m + 1));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) memo[i][j] = 0;
                else if (a[i - 1] == b[j - 1]) memo[i][j] = 1 + memo[i - 1][j - 1];
                else memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
            }
        }

        return memo[n][m];
    }
};