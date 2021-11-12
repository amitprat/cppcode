#pragma once
#include "../Header.h"

// https://www.geeksforgeeks.org/find-the-longest-path-in-a-matrix-with-given-constraints/
class LongestIncreasingSequenceInMatrix {
public:
    static void test() {
        vector<vector<int>> mat = {
            { 1, 2, 9 },
            { 5, 3, 8 },
            { 4, 6, 7 }
        };

        int l1 = longestSequence(mat);
        cout << l1 << endl;
    }

    static int longestSequence(vector<vector<int>> mat) {
        int l1 = longestSequenceRec(mat);
        int l2 = longestSequenceDP(mat);

        assert(l1 == l2);

        return l1;
    }

    static int longestSequenceRec(vector<vector<int>> mat) {
        int longest = 0;
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int curLongest = longestSequence(mat, i, j, n);
                longest = max(longest, curLongest);
            }
        }

        return longest;
    }

    static int longestSequenceDP(vector<vector<int>> mat) {
        int n = mat.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));

        int longest = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (memo[i][j] == -1) {
                    int curLongest = longestSequenceDP(mat, i, j, n, memo);
                    longest = max(longest, curLongest);
                }
            }
        }

        return longest;
    }

    static int longestSequenceDP(vector<vector<int>> mat, int r, int c, int n, vector<vector<int>>& memo) {
        if (memo[r][c] != -1) return memo[r][c];

        int longest = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == j) continue;
                int nr = r + i;
                int nc = c + j;

                if (!isValid(nr, nc, n) || mat[r][c] + 1 != mat[nr][nc]) continue;

                int curLongest = 1 + longestSequenceDP(mat, nr, nc, n, memo);
                longest = max(longest, curLongest);
            }
        }

        memo[r][c] = longest;

        return memo[r][c];
    }

    static int longestSequence(vector<vector<int>> mat, int r, int c, int n) {
        int longest = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i != j) {
                    int nr = r + i;
                    int nc = c + j;

                    if (!isValid(nr, nc, n) || mat[r][c] + 1 != mat[nr][nc]) continue;

                    int curLongest = 1 + longestSequence(mat, nr, nc, n);
                    longest = max(longest, curLongest);
                }
            }
        }

        return longest;
    }

    static bool isValid(int r, int c, int n) {
        return !(r < 0 || c < 0 || r >= n || c >= n);
    }
};