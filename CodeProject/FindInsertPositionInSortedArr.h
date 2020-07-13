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

class FindInsertPos {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) / 2 + 1;
            if (target < nums[m]) r = m - 1;
            else l = m;
        }
        if (nums[l] == target) return l;
        return nums[l] > target ? l : l + 1;
    }
};