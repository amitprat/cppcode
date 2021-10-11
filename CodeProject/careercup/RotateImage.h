#pragma once
#include "../Header.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            rotate(matrix, i, matrix[i].size());
        }
    }

    void rotate(vector<vector<int>>& matrix, int level, int m) {
        for (int j = level; j < m - level - 1; j++) {
            int tmp = matrix[level][j];
            matrix[level][j] = matrix[m - j - 1][level];
            matrix[m - j - 1][level] = matrix[m - level - 1][m - j - 1];
            matrix[m - level - 1][m - j - 1] = matrix[j][m - level - 1];
            matrix[j][m - level - 1] = tmp;
        }
    }
};