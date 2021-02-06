#pragma once
#include "../Header.h"

class ShortestSubseq {
public:
    static void test() {
        ShortestSubseq obj;
        vector<int> sub = { 1, 5, 9 };
        vector<int> arr = { 7, 5, 9, 8, 2, 1, 3, 5, 7,9,1, 1, 5, 8, 8, 9, 7 };

        auto res = obj.find(arr, sub);
        if (res.first != -1) {
            cout << "Subarray exist from " << res.first << " to " << res.second << endl;
        }
    }

    pair<int, int> find(vector<int> arr, vector<int> sub) {
        unordered_map<int, int> arrhash, subhash;
        for (int i = 0; i < sub.size(); i++) subhash[sub[i]]++;
        int count = 0;
        int start = 0;
        pair<int, int> mx = { -1,999 };

        for (int i = 0; i < arr.size(); i++) {
            int e = arr[i];
            if (!subhash[e]) continue;

            arrhash[e]++;
            if (arrhash[e] <= subhash[e]) count++;

            if (count == sub.size()) {
                while (!subhash[arr[start]] || (arrhash[arr[start]] > arrhash[arr[start]])) start++;
                if ((i - start) < (mx.second - mx.first)) mx = { start, i };

                arrhash[arr[start++]]--;
                count--;
            }
        }

        return mx;
    }
};