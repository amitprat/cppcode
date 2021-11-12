#pragma once
#include "../Header.h"

/*
https://www.careercup.com/question?id=14820665

Write a program to determine whether n/2 distintinctve pairs can be formed from given n integers where n is even and each pair's sum is divisible by given k. Numbers cannot be repeated in the pairs, that means only you can form total n/2 pairs.

bool checkPairable(List <int> nums, uint k) {
    if (k == 0) throw ...
    uint counts[k];
    for(int i =0; i < k; i++) {
        counts[k] = 0;
    }

    foreach (int num in nums) {
        counts[num %k]++;
    }
    if (counts[0] % 2 != 0) return false;
    if (k % 2 == 0) {
        if (counts[k/2] %2 != 0) return false;
    }
    for (int i = 0; i <= k/2; i++) {
        if (counts[i] != counts[k-i]) return false;
    }
    return true;
}
*/
class NBy2DivisiblePairsByK
{
public:
    static void test()
    {
        vector<int> arr = { 1,1,4,4 };
        int k = 5;

        bool res = findPairs(arr, k);
        cout << res << endl;
    }

    static bool findPairs(vector<int>& arr, int k)
    {
        int n = arr.size();
        if (n & 1) return false;
        vector<int> count(k + 1, 0);
        for (auto& e : arr) count[e % k]++;

        for (int i = 0; i <= k / 2; i++) {
            if (count[i] != count[k - i]) return false;
        }

        return true;
    }
};