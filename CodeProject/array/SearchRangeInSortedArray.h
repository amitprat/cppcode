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

class SearchRangeSortedArray {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = { -1,-1 };
        if (nums.empty()) return result;

        // search for left
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (target > nums[m]) l = m + 1;
            else r = m;
        }
        if (nums[l] != target) return result;
        else result[0] = l;

        // search for right
        l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) / 2 + 1;
            if (target < nums[m]) r = m - 1;
            else l = m;
        }
        if (nums[r] == target) result[1] = r;

        return result;
    }
};