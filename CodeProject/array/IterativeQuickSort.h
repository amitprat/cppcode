#pragma once
#include "../header.h"
using namespace std;

class IterativeQuickSort
{
public:
    void test()
    {
        vector<vector<int>> v = {
            {1,3,2,5,23,62,42,3},
            {3,6,23,6,34,24,6,6,23},
            {3,42,5,2,42,3,2,52,5,23}
        };

        for (auto arr : v) {
            cout << "Processing: {{";
            for (auto j : arr) cout << j << " ";
            cout << "} : ";

            quickSort(arr);
            cout << "Sorted = {";
            for (auto j : arr) cout << j << " ";
            cout << "}" << endl;
        }
    }

    void quickSort(vector<int>& v)
    {
        stack<pair<int, int>> st;
        st.push({ 0,v.size() - 1 });

        while (!st.empty()) {
            auto tmp = st.top(); st.pop();
            int l = tmp.first;
            int r = tmp.second;

            int p = partition(v, l, r);
            if (p > l) st.push({ l, p - 1 });

            if (p < r) st.push({ p + 1, r });
        }
    }

    int partition(vector<int>& v, int l, int r)
    {
        int pivot = v[r];
        int i = l;
        for (int j = l; j < r; j++) {
            if (v[j] < pivot) swap(v[j], v[i++]);
        }
        swap(v[i], v[r]);

        return i;
    }
};