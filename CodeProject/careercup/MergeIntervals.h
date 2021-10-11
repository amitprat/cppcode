#pragma once
#include "../Header.h"

class MergeIntervals {
public:
    static void test() {
        vector<Interval> it1 = { {1, 2},{3, 9} };
        vector<Interval> it2 = { {4, 5},{8, 10},{11, 12} };

        auto res = merge(it1, it2);
        cout << "Result: " << to_string(res) << endl;
    }

    static vector<Interval> merge(vector<Interval>& it1, vector<Interval>& it2)
    {
        vector<Interval> result;
        int i = 0, j = 0;
        while (i < it1.size() || j < it2.size()) {
            if (i == it1.size()) {
                merge(result, it2[j++]);
            }
            else if (j == it2.size()) {
                merge(result, it1[i++]);
            }
            else {
                if (less(it1[i], it2[j])) {
                    merge(result, it1[i++]);
                }
                else {
                    merge(result, it2[j++]);
                }
            }
        }

        return result;
    }

    static void merge(vector<Interval>& result, Interval it)
    {
        if (result.empty() || it.start > result.back().end) {
            result.push_back(it);
        }
        else {
            result[result.size() - 1] = { min(result.back().start, it.start), max(result.back().end, it.end) };
        }
    }

    static bool less(Interval it1, Interval it2) {
        return it1.start <= it2.start;
    }
};