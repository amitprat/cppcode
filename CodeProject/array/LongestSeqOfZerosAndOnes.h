#pragma once
#include "../Header.h"

class LongestSeqOfZerosAndOnes {
public:
    static void test() {
        int arr[] = { 0, 0, 1, 0, 1, 0, 0 };
        int n = sizeof(arr) / sizeof(arr[0]);

        longestSeq(arr, n);
    }

    static void longestSeq(int arr[], int n) {
        unordered_map<int, pair<int, int>> map;
        int curSum = 0;
        int curLen = 0;
        int startIndex = -1;
        int totalLen = 0;

        for (int i = 0; i < n; i++) {
            curSum += (arr[i] == 0) ? -1 : 1;
            if (map.find(curSum) != map.end()) {
                auto cur = i - map[curSum].first;
                if (cur > curLen) {
                    curLen = cur;
                    startIndex = map[curSum].first + 1;
                }
                totalLen += map[curSum].second;
                map[curSum].second++;
            }
            else {
                map[curSum] = { i,1 };
            }
        }

        for (int i = startIndex; i < startIndex + curLen; i++) cout << arr[i] << " ";
        cout << endl;

        cout << "CurLen " << curLen << ", TotalLen " << totalLen << endl;
    }
};