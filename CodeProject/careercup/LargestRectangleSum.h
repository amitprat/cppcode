#pragma once
#include "../Header.h"

class LargestRectangleSum {
public:
    static void test() {
        LargestRectangleSum obj;
        vector<vector<int>> mat = { { 1, 2, -1, -4, -20 },
                                    { -8, -3, 4, 2, 1 },
                                    { 3, 8, 10, 1, 3 },
                                    { -4, -1, 1, 7, -6 }
        };

        {
            auto res = obj.maxSumLeftToRight(mat);

            cout << "Max Sum = " << res << endl;
        }

        {
            auto res = obj.maxSumTopToBottom(mat);

            cout << "Max Sum = " << res << endl;
        }
    }

    int maxSumLeftToRight(vector<vector<int>> mat) {
        int n = mat.size();
        int m = mat[0].size();
        int mxSum = 0;
        pair<pair<int, int>, pair<int, int>> position;

        for (int left = 0; left < m; left++) {
            vector<int> tmp(n, 0);
            for (int right = left; right < m; right++) {
                for (int i = 0; i < n; i++) tmp[i] += mat[i][right];

                int top, bottom;
                int curSum = kadane(tmp, top, bottom);
                if (curSum > mxSum) {
                    mxSum = curSum;
                    position = { {top,left},{bottom,right} };
                }
            }
        }

        for (int i = position.first.first; i <= position.second.first; i++) {
            for (int j = position.first.second; j <= position.second.second; j++) {
                cout << setw(3) << mat[i][j] << " ";
            }
            cout << endl;
        }

        return mxSum;
    }

    int maxSumTopToBottom(vector<vector<int>> mat) {
        vector<int> result;
        int mxSum = INT_MIN;
        for (int top = 0; top < mat.size(); top++) {
            vector<int> rowSumSoFar(mat[top].size(), 0);
            for (int bottom = top; bottom < mat.size(); bottom++) {
                for (int k = 0; k < mat[bottom].size(); k++) {
                    rowSumSoFar[k] += mat[bottom][k];
                }
                int left = -1, right = -1;
                int curMax = kadane(rowSumSoFar, left, right);
                if (curMax > mxSum) {
                    mxSum = curMax;
                    result = { top,left, right, bottom };
                }
            }
        }

        for (int i = result[0]; i <= result[3]; i++) {
            for (int j = result[1]; j <= result[2]; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }

        return mxSum;
    }

    int kadane(vector<int> arr, int& start, int& end) {
        int mxSum = 0;
        int curMax = 0;
        int s = 0, e = 0;
        for (auto val : arr) {
            curMax += val;
            if (curMax > mxSum) {
                start = s;
                end = e;
                mxSum = curMax;
            }
            if (curMax < 0) {
                curMax = 0; s = e + 1;
            }
            e++;
        }

        return mxSum;
    }
};