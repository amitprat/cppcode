#pragma once
#include "../Header.h"

class MaxProfitCarRental {
public:
    static void test() {
        MaxProfitCarRental obj;
        vector<pair<int, int>> arr = { {1, 10}, {5, 8}, {4, 14}, {8,16} };
        vector<int> price = { 100, 99, 101, 50 };
        cout << obj.maxProfit(arr, price) << endl;
    }

    int maxProfit(vector<pair<int, int>> arr, vector<int> price) {
        vector<int> memo(price.size(), 0);
        return maxProfit(arr, price, price.size(), { -1,-1 }, memo);
    }

    int maxProfit(vector<pair<int, int>> arr, vector<int> price, int n, pair<int, int> prev, vector<int>& memo) {
        if (n == 0) return 0;
        if (overlap(prev, arr[n - 1])) return maxProfit(arr, price, n - 1, prev, memo);
        if (memo[n - 1] > 0) return memo[n - 1];
        memo[n - 1] = max(
            maxProfit(arr, price, n - 1, prev, memo),
            price[n - 1] + maxProfit(arr, price, n - 1, arr[n - 1], memo)
        );
        return memo[n - 1];
    }
    bool overlap(pair<int, int> f, pair<int, int> s) {
        return !(f.second <= s.first || s.second <= f.first);
    }
};