#pragma once

#include <time.h>
#include <stdlib.h>
#include <thread>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <time.h>
#include <stack>
#include <tuple>
#include <queue>
#include <mutex>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class UnionIntersectionOfSortedArrays
{
public:
    static void test(vector<int> first, vector<int> second)
    {
        UnionIntersectionOfSortedArrays obj;
        auto result = obj.findUnion(first, second);
        cout << "Union:{";
        for (auto i : result) cout << i << " ";
        cout << "}" << endl;

        result = obj.findIntersection(first, second);
        cout << "Intersection:{";
        for (auto i : result) cout << i << " ";
        cout << "}" << endl;
    }
    vector<int> findUnion(vector<int> first, vector<int> second)
    {
        int i = 0, j = 0;
        vector<int> result;
        while (i < first.size() && j < second.size()) {
            if (first[i] == second[j]) {
                result.push_back(first[i]);
                i++; j++;
            }
            else if (first[i] < second[j]) {
                result.push_back(first[i++]);
            }
            else {
                result.push_back(second[j++]);
            }
        }

        return result;
    }

    vector<int> findIntersection(vector<int> first, vector<int> second)
    {
        int i = 0, j = 0;
        vector<int> result;
        while (i < first.size() && j < second.size()) {
            if (first[i] == second[j]) {
                result.push_back(first[i]);
                i++; j++;
            }
            else if (first[i] < second[j]) i++;
            else j++;
        }

        return result;
    }
};