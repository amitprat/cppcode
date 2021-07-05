#pragma once
#include "../Header.h"

class FindSurpasser {
public:
    static void test() {
        FindSurpasser obj;
        vector<int> arr = { 2, 7, 5, 3, 0, 8, 1 };
        auto res = obj.findSurpasser(arr);
        cout << to_string(res) << endl;
    }

    vector<int> findSurpasser(vector<int>& arr) {
        vector<int> result;
        unordered_map<int, int> map;
        vector<int> dup = arr;

        int n = arr.size();
        vector<int> tmp(n);
        mergeSort(dup, 0, n - 1, tmp, map);

        for (int i = 0; i < n; i++) {
            result.push_back(n - i - 1 - map[arr[i]]);
        }

        return result;
    }

    void mergeSort(vector<int>& dup, int l, int r, vector<int>& tmp, unordered_map<int, int>& map) {
        if (l >= r) return;

        int m = (l + r) / 2;
        mergeSort(dup, l, m, tmp, map);
        mergeSort(dup, m + 1, r, tmp, map);
        merge(dup, l, m, r, tmp, map);
    }

    void merge(vector<int>& dup, int l, int m, int r, vector<int>& tmp, unordered_map<int, int>& map) {
        for (int i = l; i <= m; i++) tmp[i] = dup[i];
        for (int i = m + 1; i <= r; i++) tmp[i] = dup[i];

        int i = l, j = m + 1, k = l;
        int c = 0;
        while (i <= m && j <= r) {
            if (tmp[i] <= tmp[j]) {
                map[tmp[i]] += c;
                dup[k++] = tmp[i++];
            }
            else {
                c++;
                dup[k++] = tmp[j++];
            }
        }

        while (i <= m) {
            map[tmp[i]] += c;
            dup[k++] = tmp[i++];
        }

        while (j <= r) dup[k++] = tmp[j++];
    }
};