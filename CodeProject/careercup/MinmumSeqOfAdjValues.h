#pragma once
#include "../Header.h"

/*
https://www.careercup.com/question?id=5653018213089280

Determine minimum sequence of adjacent values in the input parameter array that is greater than input parameter sum.

Eg
Array 2,1,1,4,3,6. and Sum is 8
Answer is 2, because 3,6 is minimum sequence greater than 8.
*/
class MinimumSeqOfAdjValues
{
public:
    static void test()
    {
        MinimumSeqOfAdjValues obj;
        vector<int> arr = { 2,1,1,4,3,6 };
        int sum = 8;

        auto res = obj.getMinSeq(arr, sum);
        cout << to_string(res) << endl;
    }

    vector<int> getMinSeq(vector<int> arr, int sum)
    {
        int curSum = 0;
        int s = 0;
        int minLen = INT_MAX;
        vector<int> indices;
        vector<int> res;
        for (int e = 0; e < arr.size(); e++)
        {
            curSum += arr[e];
            if (curSum >= sum) {
                while (s <= e && curSum - arr[s] >= sum) {
                    curSum -= arr[s++];
                }
                if (e - s + 1 < minLen)
                {
                    minLen = e - s + 1;
                    indices = { s, e };
                }
                curSum -= arr[s++];
            }
        }

        for (int i = indices[0]; i <= indices[1]; i++) res.push_back(arr[i]);
        return res;
    }
};