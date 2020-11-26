#pragma once
#include "../header.h"
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;

        // find pivot
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > nums[hi]) lo = mid + 1;
            else hi = mid;
        }

        // now bsearch with rotation as offset
        int rot = lo;
        lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int realmid = (mid + rot) % nums.size();
            if (nums[realmid] == target) return realmid;
            if (target < nums[realmid]) hi = mid - 1;
            else lo = mid + 1;
        }

        return -1;
    }
};