#pragma once
#include "../Header.h"

class IsInterleaved
{
public:
    static void test()
    {
        string a = "abcd";
        string b = "xyz";
        string c = "axybczd";

        bool res = isInterleaved(a, b, c);
        cout << "Is Interleaved? " << res << endl;
    }

    static bool isInterleaved(string a, int idx1, string b, int idx2, string c, int idx3)
    {
        if (idx1 == a.length() && idx2 == b.length() && idx3 == c.length()) return true;
        if (idx1 > a.length() || idx2 > b.length() || idx3 >= c.length()) return false;

        if (idx1 < a.length() && a[idx1] == c[idx3] && isInterleaved(a, idx1 + 1, b, idx2, c, idx3 + 1)) return true;
        if (idx2 < b.length() && b[idx2] == c[idx3] && isInterleaved(a, idx1, b, idx2 + 1, c, idx3 + 1)) return true;

        return false;
    }

    static bool isInterleaved(string a, string b, string c)
    {
        int n = a.length();
        int m = b.length();
        vector<vector<bool>> memo(n + 1, vector<bool>(m + 1, false));

        for (int i = 0; i <= a.size(); i++)
        {
            for (int j = 0; j <= b.size(); j++)
            {
                if (i == 0 && j == 0) memo[i][j] = true;
                else if (i == 0) memo[i][j] = c[i + j - 1] == b[j - 1];
                else if (j == 0) memo[i][j] = c[i + j - 1] == a[i - 1];
                else if (c[i + j - 1] == a[i - 1] || c[i + j - 1] == b[j - 1]) {
                    if (c[i + j - 1] == a[i - 1]) memo[i][j] = memo[i][j] || memo[i - 1][j];
                    if (c[i + j - 1] == b[j - 1]) memo[i][j] = memo[i][j] || memo[i][j - 1];
                }
            }
        }

        return memo[n][m];
    }
};