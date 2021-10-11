#pragma once
#include "../Header.h"

class NumberOccurringOnlyOnce {
public:
    static void test() {
        int arr[] = { 2,1,4,5,1,4,2,2,4,1 };
        int n = sizeof(arr) / sizeof(int);
        int bitsize = 0;
        for (int i = 0; i < n; i++) {
            bitsize = max(bitsize, (int)log2(arr[i]) + 1);
        }
        auto res = addNumMod3(arr, n);
        cout << res << endl;
    }

    static int addNumMod3(int arr[], int n) {
        vector<int> result;
        for (int i = 0; i < n; i++) {
            result = addMod3(result, toMod3(arr[i]));
        }
        std::reverse(result.begin(), result.end());
        return toMod10(result);
    }

    static vector<int> addMod3(vector<int> num1, vector<int> num2) {
        int i = 0, j = 0;
        vector<int> result;
        while (i < num1.size() || j < num2.size()) {
            if (i == num1.size()) {
                result.push_back(num2[j++] % 3);
            }
            else if (j == num2.size()) {
                result.push_back(num1[i++] % 3);
            }
            else {
                result.push_back((num1[i++] + num2[j++]) % 3);
            }
        }

        return result;
    }

    static int toMod10(vector<int> num) {
        int result = 0;
        for (auto i : num) {
            result = result * 3 + i;
        }
        return result;
    }

    static vector<int> toMod3(int num) {
        vector<int> result;
        while (num) {
            result.push_back(num % 3);
            num /= 3;
        }
        return result;
    }

    static int addBitMod3(int arr[], int n, int bitsize) {
        if (bitsize == 0) return 0;
        int cur = addBitMod3(arr, n, bitsize - 1);

        int s = 0;
        for (int j = 0; j < n; j++) {
            int v = (arr[j] >> bitsize - 1) & 1;
            s = (s + v) % 3;
        }
        cur = s * pow(2, bitsize - 1) + cur;

        return cur;
    }
};