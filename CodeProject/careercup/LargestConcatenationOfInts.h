#pragma once
#include "../Header.h"

// https://www.careercup.com/question?id=7781671
class LargestConcatenationOfInts
{
public:
    static void test() {
        vector<int> arr = { 4, 94, 9, 14, 1 };
        sort(arr.begin(), arr.end(), [](const auto& f, const auto& s) {
            return stoi(to_string(f) + to_string(s)) > stoi(to_string(s) + to_string(f));
            });

        cout << to_string(arr) << endl;
    }
};