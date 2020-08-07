#pragma once

#include <time.h>
#include <stdlib.h>
#include <thread>
#include <vector>
#include <iostream>
#include <atomic>
#include <mutex>
#include <time.h>
#include <fstream>
#include <tuple>
#include <queue>
#include <unordered_map>
#include <string>
#include <unordered_set>
using namespace std;

class FindInsertPositionInSortedArray {
public:
    static void test() {
        FindInsertPositionInSortedArray obj;
        vector<pair<vector<int>, int>> tests = {
            {{1,3,5,6}, 5},
            {{1,3,5,6}, 2},
            {{1,3,5,6}, 7},
            {{1,3,5,6}, 0},
            {{3,3,3,3}, 3}
        };
        for (auto& test : tests) {
            cout << "Insert Position: " << obj.findInsertPosition(test.first, test.second) << endl;
            cout << "Insert Position: " << obj.findInsertPosition2(test.first, test.second) << endl;
            cout << endl << endl;
        }
    }

    // first the index of last element which is less than or equal to target
    // if we find such position then insert at +1 position otherwise at current position
    int findInsertPosition(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (target <= nums[m]) r = m - 1;
            else l = m;
        }
        return nums[l] < target ? l + 1 : l;
    }

    // look for first greater element
    // if there is none, then we need to insert at +1 position
    int findInsertPosition2(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (target >= nums[m]) l = m + 1;
            else r = m;
        }
        return nums[l] > target ? l : l + 1;
    }
};