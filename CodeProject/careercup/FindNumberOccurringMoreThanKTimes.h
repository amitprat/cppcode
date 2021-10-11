#pragma once
#include "../Header.h"

//https://www.careercup.com/question?id=14099679
class FindNumberOccurringMoreThanKTimes
{
public:
    static void test() {
        int arr[] = { 4,4,4,1,2,3,5,5,5,5,1,2,3,6 };
        auto a_map = findOverNth(arr, sizeof(arr) / sizeof(int), 3);
        cout << sizeof(arr) / sizeof(int) << endl;
        cout << a_map.size() << endl;
        for (auto elem : a_map)
        {
            cout << elem.first << " " << elem.second << endl;
        }
    }

    static unordered_map<int, int> findOverNth(int arr[], int n, int k)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++)
        {
            map[arr[i]]++;
            if (map.size() == k)
            {
                for (auto it = map.begin(); it != map.end();)
                {
                    if (it->second == 1) map.erase(it++);
                    else it++;
                }
            }
        }
        for (auto it = map.begin(); it != map.end(); it++)
        {
            it->second = 0;
        }
        for (int i = 0; i < n; i++)
        {
            if (map.find(arr[i]) != map.end())
            {
                map[arr[i]]++;
            }
        }
        for (auto it = map.begin(); it != map.end();)
        {
            if (it->second < n / k) map.erase(it++);
            else it++;
        }

        return map;
    }
};