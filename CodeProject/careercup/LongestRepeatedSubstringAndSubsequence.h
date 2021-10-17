#pragma once
#include "../Header.h"

/*
* https://www.careercup.com/question?id=5931067269709824
*
Given a string (1-d array) , find if there is any sub-sequence that repeats itself.
Here, sub-sequence can be a non-contiguous pattern, with the same relative order.

Eg:

1. abab <------yes, ab is repeated
2. abba <---- No, a and b follow different order
3. acbdaghfb <-------- yes there is a followed by b at two places
4. abcdacb <----- yes a followed by b twice

The above should be applicable to ANY TWO (or every two) characters in the string and optimum over time.

In the sense, it should be checked for every pair of characters in the string.
*/
class LongestRepeatedSubstringAndSubsequence
{
public:
    static void test()
    {
        string s = "aabaabaabaabaabaabaab";
        LongestRepeatedSubstringAndSubsequence obj;

        auto res = obj.isPeriod(s);
        cout << "Is Periodic = " << res << endl;
        if (res) {
            auto p = obj.getPeriod(s);
            cout << "Period = " << p << endl;
        }

        {
            string s = "abab";
            auto res = obj.getLongestRepeatedSubseqDP(s);
            cout << "longest subsequence: " << res << endl;
        }

        {
            string s = "abba";
            auto res = obj.getLongestRepeatedSubseqDP(s);
            cout << "longest subsequence: " << res << endl;
        }

        {
            string s = "acbdaghfb";
            auto res = obj.getLongestRepeatedSubseqDP(s);
            cout << "longest subsequence: " << res << endl;
        }

        {
            string s = "abcdacb";
            auto res = obj.getLongestRepeatedSubseqDP(s);
            cout << "longest subsequence: " << res << endl;
        }
    }

    bool isPeriod(string s)
    {
        string rep = s + s;
        string part = s.substr(1, s.length() - 2);

        return rep.find(part) != string::npos;
    }

    string getPeriod(string s)
    {
        int l = s.length();
        for (int i = l / 2; i > 0; i--)
        {
            if (l % i == 0 && isRepeat(s, i, l)) return s.substr(0, i);
        }

        return "";
    }

    bool isRepeat(string s, int patLen, int totalLen)
    {
        string period = s.substr(0, patLen);
        int j = patLen;

        while (j + patLen <= totalLen)
        {
            if (period != s.substr(j, patLen)) return false;
            j += patLen;
        }

        return true;
    }

    string getLongestRepeatedSubseq(string s)
    {
        return getLongestRepeatedSubseqRec(s);
    }

    string getLongestRepeatedSubseqRec(string s)
    {
        string res;

        auto len = longestRepeatedSubseq(s, s, 0, 0, "", res);
        cout << "Len: " << len << endl;

        return res;
    }

    int longestRepeatedSubseq(string s1, string s2, int i, int j, string cur, string& res)
    {
        if (i >= s1.length() || j >= s2.length()) {
            if (cur.length() > res.length()) res = cur;
            return 0;
        }

        if (i != j && s1[i] == s2[j]) return 1 + longestRepeatedSubseq(s1, s2, i + 1, j + 1, cur + s1[i], res);
        else return max(longestRepeatedSubseq(s1, s2, i + 1, j, cur, res), longestRepeatedSubseq(s1, s2, i, j + 1, cur, res));
    }

    bool getLongestRepeatedSubseqDP(string s)
    {
        int l = lps(s, s);
        return (l > 1) ? true : false;
    }

    int lps(string s1, string s2)
    {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0) memo[i][j] = 0;
                else if (i != j && s1[i - 1] == s2[j - 1]) memo[i][j] = 1 + memo[i - 1][j - 1];
                else memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
            }
        }

        //cout << to_string(memo) << endl;

        return memo[n][m];
    }
};