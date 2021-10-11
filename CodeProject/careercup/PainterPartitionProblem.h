#pragma once
#include "../Header.h"

class PainterPartitionProblem {
public:
    static void test() {
        PainterPartitionProblem obj;
        int k = 3;
        vector<int> arr = { 10, 20, 60, 50, 30, 40 };

        cout << "Partition = " << obj.partitionDP(arr, k) << endl;
    }

    int partition(vector<int>& arr, int l, int r, int k)
    {
        if (k == 1) return sum(arr, l, r);
        if (l == r) return arr[l];

        int result = INT_MAX;
        for (int i = l; i <= r; i++) {
            int cur = max(partition(arr, l, i, k - 1), sum(arr, i + 1, r));
            result = min(result, cur);
        }

        return result;
    }

    int partitionDP(vector<int>& arr, int k)
    {
        int n = arr.size();
        vector<vector<int>> table(k + 1, vector<int>(n + 1, 0));

        // for k=1
        for (int j = 1; j <= n; j++) table[1][j] = sum(arr, 0, j - 1);

        // for n=1
        for (int i = 1; i <= k; i++) table[i][1] = arr[0];

        for (int i = 2; i <= k; i++) {
            for (int j = 2; j <= n; j++) {
                int best = INT_MAX;
                for (int p = 1; p <= j; p++) {
                    int cur = max(table[i - 1][p], sum(arr, p, j - 1));
                    best = min(best, cur);
                }
                table[i][j] = best;
            }
        }

        return table[k][n];
    }

    int sum(vector<int>& arr, int l, int r) {
        int s = 0;
        for (int i = l; i <= r; i++) s += arr[i];

        return s;
    }
};