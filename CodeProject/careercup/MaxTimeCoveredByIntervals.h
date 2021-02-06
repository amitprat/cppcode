#pragma once
#include "../Header.h"

/*
Given a list of arrays of time intervals, write a function that calculates the total amount of time covered by the intervals.
For example:
input = [(1,4), (2,3)]
return 3
input = [(4,6), (1,2)]
return 3
input = {{1,4}, {6,8}, {2,4}, {7,9}, {10, 15}}
return 11

public static int mergeSegments(int[][] segments) {
        Arrays.sort(segments, (x, y) -> x[0] - y[0]);

        int result = 0;
        int last = 0;
        for(int[] seg : segments) {
            result += Math.max(seg[1] - Math.max(last, seg[0]), 0);
            last = Math.max(last, seg[1]);
        }
        return result;
    }
*/
class MaxTimeConvered {
public:
    static void test() {
        MaxTimeConvered obj;
        vector<pair<int, int>> input = { {1,4}, {6,8}, {2,4}, {7,9}, {10, 15} };
        cout << obj.maxTimeConvered2(input) << endl;
    }

    int maxTimeConvered(vector<pair<int, int>> input) {
        sort(input.begin(), input.end(), [](const auto& f, const auto& s) {return f.first < s.first; });
        int result = 0;
        int last = 0;
        for (int i = 0; i < input.size(); i++) {
            result += max(input[i].second - max(input[i].first, last), 0);
            last = max(input[i].second, last);
        }
        return result;
    }

    int maxTimeConvered2(vector<pair<int, int>> input) {
        sort(input.begin(), input.end(), [](const auto& f, const auto& s) {return f.first < s.first; });
        int result = 0;
        int i = 0, j = 1;
        while (j < input.size()) {
            if (input[j].first >= input[j - 1].second) {
                result += input[j - 1].second - input[i].first;
                i = j;
            }
            j++;
        }
        result += input[j - 1].second - input[i].first;
        return result;
    }
};