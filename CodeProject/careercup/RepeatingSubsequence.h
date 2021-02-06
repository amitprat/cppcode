#pragma once
#include "../Header.h"

/*
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

class LongestCommonSubsequence {
public:
    static void test() {
        LongestCommonSubsequence obj;
        string X = "AGGTAB";
        string Y = "GXTXAYB";
        cout << "Longest Common Subseq (Using Recursion) = " << obj.lcs(X, Y) << endl;
        cout << "Longest Common Subseq (Using Dynamic Programming) = " << obj.lcsDp(X, Y) << endl;
    }

    int lcs(string x, string y) {
        return lcs(x, x.length(), y, y.length());
    }

    int lcsDp(string x, string y) {
        vector<vector<int>> memo(x.length() + 1, vector<int>(y.length() + 1, 0));
        for (int i = 1; i <= x.length(); i++) {
            for (int j = 1; j <= y.length(); j++) {
                memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
                if (x[i - 1] == y[j - 1]) memo[i][j] = max(memo[i][j], memo[i - 1][j - 1] + 1);
            }
        }
        return memo[x.length()][y.length()];
    }
private:
    int lcs(string x, int n, string y, int m) {
        if (n == 0 || m == 0) return 0;
        if (x[n - 1] == y[m - 1]) return 1 + lcs(x, n - 1, y, m - 1);
        return max(lcs(x, n - 1, y, m), lcs(x, n, y, m - 1));
    }
};
class RepeatingSubsequence {
public:
    static void test() {
        RepeatingSubsequence obj;
        string s = "acbdaghfb";
        cout << "Is Repeating Subseq(Recursion) = " << obj.isRepeatingSubseq(s) << endl;
        cout << "Is Repeating Subseq(DP) = " << obj.isRepeatingSubseqDP(s) << endl;
    }

    string isRepeatingSubseqDP(string s) {
        int n = s.length();
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
                if (i != j && s[i - 1] == s[j - 1]) memo[i][j] = max(memo[i][j], memo[i - 1][j - 1] + 1);
            }
        }
        return (memo[n][n] > 1) ? "True" : "False";
    }

    string isRepeatingSubseq(string s) {
        auto len = lcs(s, s.length(), s, s.length());
        return len > 1 ? "True" : "False";
    }

private:
    int lcs(string x, int n, string y, int m) {
        if (n == 0 || m == 0) return 0;
        if (n != m && x[n - 1] == y[m - 1]) return 1 + lcs(x, n - 1, y, m - 1);
        return max(lcs(x, n - 1, y, m), lcs(x, n, y, m - 1));
    }
};

/*
We can implement this as a variation of the longest common subsequence in O(n^2), using dynamic programming. In the general problem, given two strings, 'a' and 'b', we find the longest common subsequence by computing a matrix M of size len(a)* len(b) defined as follows: M[ i ][ j ] is the value of the longest common subsequence between the strings "a0...ai" and "b0...bj". In particular, if a[ i ] == b[ j ], then M[ i ][ j ] = max (1 + M[ i-1 ][ j-1], M[ i - 1 ][ j ], M[ i ][ j-1 ]) , otherwise M[ i ][ j ] = max (M[ i - 1 ][ j ], M[ i ][ j-1 ]). The value of longest common subsequence is therefore M[ len(a) -1 ][ len(b) - 1].

Now we can modify the longest_common_subsequence(a, a) to find the value of the longest repeated subsequence in a by excluding the cases when i == j, (which we know are always equal in this case). Here is the code in python:


def longest_repeated_subsequence(a):
    n = len(a)

    M = [ [0] * n for i in range(n) ]

    M[0][0] = 0

    # First row
    for j in range(1, n):
        if a[0] == a[j]:
            M[0][j] = 1
        else: M[0][j] = M[0][j-1]

    # First column
    for i in range(1, n):
        if a[i] == a[0]:
            M[i][0] = 1
        else: M[i][0] = M[i-1][0]

    for i in range(1, n):
        for j in range(1, n):
            if a[i] == a[j] and i != j:
                M[i][j] = max(
                    M[i-1][j-1] + 1, M[i-1][j], M[i][j-1])
            else:
                M[i][j] = max(M[i-1][j], M[i][j-1])

    return M[n-1][n-1]
and, to test it:


def main():
    strings = [
    'abab',
        'abba',
        'acbdaghfb',
        'abcdacb'
    ]

    for s in strings:
        print (longest_repeated_subsequence(s) > 1)
*/