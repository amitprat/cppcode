#pragma once
#include "../Header.h"

class CoinCombination {
public:
    static void test() {
        int arr[] = { 10,15,20 };
        int sum = 1000;
        generate(arr, sum);
    }

    static void generate(int arr[]) {
        unordered_set<int> s;
        s.insert(0);
        for (int i = 1; i <= 1000; i++) {
            for (int j = 0; j < 3; j++) {
                if (s.find(i - arr[j]) != s.end()) {
                    cout << i << " ";
                    s.insert(i);
                    break;
                }
            }
        }
    }

    // mn=10
    static void generate(int arr[], int sum) {
        int c1 = 1, c2 = 1, c3 = 1;
        int mn = 1;
        while (mn < 1000) {
            mn = min(arr[0] * c1, min(arr[1] * c2, arr[2] * c3));
            cout << mn << " ";
            if (mn == c1 * arr[0]) c1++;
            if (mn == c2 * arr[1]) c2++;
            if (mn == c3 * arr[2]) c3++;
        }
    }
};