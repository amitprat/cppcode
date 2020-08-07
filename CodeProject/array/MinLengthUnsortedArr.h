#include <time.h>
#include <stdlib.h>
#include <thread>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class IterativeQuickSort
{
public:
    void test()
    {
        vector<vector<int>> v = {
            {10, 12, 20, 30, 25,40, 32, 31, 35, 50, 60}
        };

        for (auto arr : v) {
            cout << "Processing: {{";
            for (auto j : arr) cout << j << " ";
            cout << "} : ";

            auto res = minLengthUnsortedSubArr(arr);
            cout << "Sorted = {";
            for (auto j : res) cout << j << " ";
            cout << "}" << endl;
        }
    }

    vector<int> minLengthUnsortedSubArr(vector<int>& v)
    {
    }
};