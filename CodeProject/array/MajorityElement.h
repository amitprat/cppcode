#pragma once
#include "../header.h"

class MajorityElement
{
public:
    static void test()
    {
        MajorityElement obj;
        vector<int> v = {1, 2, 4, 2, 1, 3, 2, 2, 1, 2, 1, 2, 1};
        cout << obj.majorityElementHalf(v).first << endl;
        auto res = obj.majorityElementOneThird(v);
        cout << res.first << "," << res.second << endl;
    }

    pair<int, int> majorityElementHalf(vector<int> &input)
    {
        int candidate = -1;
        int count = 0;
        for (int i = 0; i < input.size(); i++)
        {
            if (count == 0) candidate = input[i];
            
            if (input[i] == candidate)
                count++;
            else
                count--;
        }

        // validate candidate
        count = 0;
        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == candidate)
                count++;
        }

        if (count > input.size() / 2)
            return {candidate, count};
        return {-1, -1};
    }

    pair<int, int> majorityElementOneThird(vector<int> &input)
    {
        pair<int, int> candidate1 = {-1, 1};
        pair<int, int> candidate2 = {-1, 1};
        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == candidate1.first)
                candidate1.second++;
            else
            {
                candidate1.second--;

                if (input[i] == candidate2.first)
                    candidate2.second++;
                else
                    candidate2.second--;
            }

            if (candidate1.second == 0)
                candidate1 = {input[i], 1};
            if (candidate2.second == 0)
                candidate2 = {input[i], 1};
        }

        if (candidate1.second <= 0 && candidate2.second <= 0)
            return {-1, -1};

        // validate candidate
        int count1 = 0, count2 = 0;
        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == candidate1.first)
                count1++;
            if (input[i] == candidate2.first)
                count2++;
        }

        pair<int, int> result = {-1, -1};
        if (count1 > input.size() / 3)
            result.first = candidate1.first;
        if (count2 > input.size() / 3)
            result.second = candidate2.first;

        return result;
    }

    vector<int> majorityElement(vector<int> &nums)
    {
        int cnt1 = 0, cnt2 = 0;
        int a, b;
        for (int n : nums)
        {
            if (cnt1 == 0 || n == a)
            {
                cnt1++;
                a = n;
            }
            else if (cnt2 == 0 || n == b)
            {
                cnt2++;
                b = n;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = cnt2 = 0;
        for (int n : nums)
        {
            if (n == a)
                cnt1++;
            else if (n == b)
                cnt2++;
        }
        vector<int> result;
        if (cnt1 > nums.size() / 3)
            result.push_back(a);
        if (cnt2 > nums.size() / 3)
            result.push_back(b);
        return result;
    }
};

// majority element
// https://www.careercup.com/question?id=14099679

/*
Design an algorithm that, given a list of n elements in an array, finds all the elements that appear more than n/3 times 
in the list. The algorithm should run in linear time ( n >=0 )

You are expected to use comparisons and achieve linear time. No hashing/excessive space/ and don't use standard linear
 time deterministic selection algo

I have a correct solution to it. I am gonna post a small piece of code. You need a compiler that support C++ 11 to run the code.
But don't worry if you don't have such one. I know that most of people would prefer English to code. I will explain the idea in English afterward, but, excuse me for I am not a native English speaker.
The algorithm here is actually not designed dedicatedly to solve this question but to handle a more general case:
Given an array of N numbers, finds all the elements that appear more than N/M times and report the their frequencies.
The time complexity is O(2*N*logM) and space complexity is O(M)
For this question, M = 3, so the time is O(2log3 N) = O(N), space is O(3) = O(1);
*/

#include <iostream>
#include <map>
#include <algorithm>
typedef std::map<int, int> Map;
Map findOverNth(int arr[], int size, int n)
{
    Map ret_map;
    typedef Map::value_type Elem; //pair<CONST int, int>
    int total = 0;
    std::for_each(arr, arr + size, [&, n](int val) {
        auto ret_pair = ret_map.insert(Elem(val, 0));
        ++(*ret_pair.first).second;
        ++total;
        if (ret_map.size() == n)
            for (auto iter = ret_map.begin(); iter != ret_map.end();)
            {
                --(*iter).second;
                --total;
                if ((*iter).second == 0)
                    ret_map.erase(iter++);
                else
                    iter++;
            }
    });
    std::for_each(ret_map.begin(), ret_map.end(), [](Elem &elem) { elem.second = 0; });
    std::for_each(arr, arr + size, [&ret_map](int val) {if (ret_map.find(val) != ret_map.end()) ret_map[val] ++; });
    for (auto iter = ret_map.begin(); iter != ret_map.end();)
    {
        if ((*iter).second <= size / n)
            ret_map.erase(iter++);
        else
            iter++;
    }
    return ret_map;
}
using namespace std;
int main()
{
    //int arr[] = {5,6,7,8, 10, 4,4, 4, 4,1, 1,1};
    int arr[] = {5, 6, 7, 8, 10, 10, 10, 10, 10, 10, 4, 4, 4, 4, 4, 1, 1, 1, 1};
    auto a_map = findOverNth(arr, sizeof(arr) / sizeof(int), 4);
    cout << sizeof(arr) / sizeof(int) << endl;
    //cout<<a_map.size()<<endl;
    for each (auto elem in a_map)
    {
        cout << elem.first << " " << elem.second << endl;
    }
}