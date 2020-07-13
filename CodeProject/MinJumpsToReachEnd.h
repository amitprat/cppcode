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

class FindMInJumps {
public:
    static void test() {
        FindMInJumps obj;
        vector<int> nums = { 2,3,2,1,4 };
        cout << obj.jump(nums) << endl;
    }
    int jump(vector<int>& nums) {
        vector<int> memo;
        for (int i = 0; i < nums.size(); i++) memo.push_back(INT_MAX);
        calculate(nums, 0, memo);
        for (auto m : memo) cout << m << " ";
        cout << endl;
        return memo[0];
    }

private:
    int calculate(vector<int>& nums, int index, vector<int>& memo) {
        if (index >= nums.size()) return INT_MAX;
        if (index == nums.size() - 1) {
            return 0;
        }
        if (memo[index] != INT_MAX) return memo[index];
        for (int i = 1; i <= nums[index]; i++) {
            int tmp = 1 + calculate(nums, index + i, memo);
            memo[index] = min(memo[index], tmp);
        }

        return memo[index];
    }
};