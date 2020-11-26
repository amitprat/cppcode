#pragma once
#include "../header.h"
using namespace std;

class FindMimJumpsToReachEndOfArray {
public:
    static void test() {
        FindMimJumpsToReachEndOfArray obj;
        vector<int> nums = { 2,3,2,1,4 };
        cout << obj.jump(nums) << endl;
        cout << obj.minJumpsGreedy(nums) << endl;
    }
    int jump(vector<int>& nums) {
        vector<int> memo;
        for (int i = 0; i < nums.size(); i++) memo.push_back(INT_MAX);
        calculate(nums, 0, memo);
        for (auto m : memo) cout << m << " ";
        cout << endl;
        return memo[0];
    }

    int minJumpsGreedy(vector<int>& nums) {
        int jumps = 0, curEnd = 0, curFarthest = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            curFarthest = max(curFarthest, i + nums[i]);
            if (curEnd == i) {
                jumps++;
                curEnd = curFarthest;
            }
        }

        return jumps;
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