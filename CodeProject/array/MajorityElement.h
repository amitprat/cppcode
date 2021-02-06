#pragma once
#include "../header.h"

class MajorityElement {
public:
    static void test() {
        MajorityElement obj;
        vector<int> v = { 1,2,4,2,1,3,2,2,1,2,1,2,1 };
        cout << obj.majorityElementHalf(v).first << endl;
        auto res = obj.majorityElementOneThird(v);
        cout << res.first << "," << res.second << endl;
    }

    pair<int, int> majorityElementHalf(vector<int>& input) {
        int candidate = -1;
        int count = 0;
        for (int i = 0; i < input.size(); i++) {
            if (count == 0) candidate = input[i];
            if (input[i] == candidate) count++;
            else count--;
        }

        // validate candidate
        count = 0;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == candidate) count++;
        }

        if (count > input.size() / 2) return { candidate, count };
        return { -1,-1 };
    }

    pair<int, int> majorityElementOneThird(vector<int>& input) {
        pair<int, int> candidate1 = { -1,1 };
        pair<int, int> candidate2 = { -1,1 };
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == candidate1.first) candidate1.second++;
            else {
                candidate1.second--;

                if (input[i] == candidate2.first) candidate2.second++;
                else candidate2.second--;
            }

            if (candidate1.second == 0) candidate1 = { input[i],1 };
            if (candidate2.second == 0) candidate2 = { input[i],1 };
        }

        if (candidate1.second <= 0 && candidate2.second <= 0) return { -1,-1 };

        // validate candidate
        int count1 = 0, count2 = 0;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == candidate1.first) count1++;
            if (input[i] == candidate2.first) count2++;
        }

        pair<int, int> result = { -1,-1 };
        if (count1 > input.size() / 3) result.first = candidate1.first;
        if (count2 > input.size() / 3) result.second = candidate2.first;

        return result;
    }
};