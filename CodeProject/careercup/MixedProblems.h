#pragma once
#include "../Header.h"

class MixedProblems {
public:
    void test()
    {
        vector<int> arr = { 1, 2, 3, 4 };
        int k = 20;
        int res = countSubArrays(arr, k);
        cout << res << endl;

        cout << next_permutation("34722641") << endl;

        vector<Point> points = { {1,2},{3,1},{0,2},{1,1},{3,4},{1,0},{0,1},{0,0} };
        auto res1 = kClosest(points, { 0,0 }, 5);
        for (auto e : res1) {
            cout << e.to_string() << ", ";
        }
        cout << endl;

        vector<Interval> intervals = { {1,4}, {6,8}, {2,4}, {7,9}, {10, 15} };
        cout << "Time covered = " << totalIntervalCovered(intervals) << endl;

        permutationDistance(5);

        vector<int> arr1 = { 2,3,1,4 };
        auto res2 = multiplyExceptSelf(arr1);
        for (auto e : res2) cout << e << " ";
        cout << endl;
    }

private:
    int countSubArrays(vector<int>& arr, int k) {
        int prod = 1;
        int s = 0, e = 0;
        int res = 0;
        while (s <= e && e <= arr.size()) {
            if (prod <= k) {
                if (prod <= k) res += e - s;
                if (e < arr.size()) prod *= arr[e];
                e++;
            }
            else {
                prod /= arr[s++];
            }
            cout << res << endl;
        }

        return res;
    }

    string next_permutation(string str) {
        if (str.length() == 1) return str;
        int r = str.length() - 2;
        while (r >= 0 && str[r] > str[r + 1]) {
            r--;
        }
        if (r < 0) return "Not possible";
        int next = r + 1;
        int j = r + 1;
        while (j < str.length()) {
            if (str[j] > str[r] && str[j] < str[next]) next = j;
            j++;
        }

        swap(str[r], str[next]);
        cout << r << " " << next << endl;
        sort(str.begin() + r + 1, str.end());

        return str;
    }

    struct Point {
        int x, y;
        string to_string() {
            return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
        }
    };

    int distance(Point p1, Point p2) {
        return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    }

    int partition(vector<Point>& points, int l, int r, Point origin) {
        int i = 0;
        int pivotDistance = distance(origin, points[r]);
        for (int j = i; j < r; j++) {
            if (distance(points[j], origin) <= pivotDistance) {
                swap(points[j], points[i++]);
            }
        }
        swap(points[i], points[r]);

        return i;
    }

    int selectionSort(vector<Point>& points, int l, int r, Point source, int k) {
        int p = partition(points, l, r, source);
        int q = p - l + 1;
        if (q == k) return p;

        if (q < k) return selectionSort(points, p + 1, r, source, k - q);
        return selectionSort(points, l, p - 1, source, k);
    }

    vector<Point> kClosest(vector<Point> points, Point source, int k) {
        int l = 0, r = points.size() - 1;
        auto p = selectionSort(points, l, r, source, k);

        return { points.begin(), points.begin() + p + 1 };
    }

    struct Interval {
        int start, end;
        string to_string() {
            return "(" + std::to_string(start) + "," + std::to_string(end) + ")";
        }
    };

    int totalIntervalCovered(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& f, const auto& s) {
            return f.start < s.start;
            });
        int timeCovered = 0;
        int last = 0;
        for (auto it : intervals) {
            timeCovered += max(it.end - max(last, it.start), 0);
            last = max(last, it.end);
        }

        return timeCovered;
    }

    bool generatePermutation(vector<int>& arr, unordered_set<int> visited, int n)
    {
        if (visited.size() == n) return true;

        for (int i = 1; i <= n; i++) {
            if (visited.find(i) != visited.end()) continue;
            for (int j = 0; j < arr.size() - i - 1; j++) {
                if (arr[j] == 0 && arr[j + i + 1] == 0) {
                    arr[j] = arr[j + i + 1] = i;
                    visited.insert(i);
                    if (generatePermutation(arr, visited, n)) return true;
                    arr[j] = arr[j + i + 1] = 0;
                    visited.erase(i);
                }
            }
        }

        return false;
    }

    void permutationDistance(int n) {
        vector<int> arr(2 * n, 0);
        unordered_set<int> visited;

        bool res = generatePermutation(arr, visited, n);
        if (res) {
            cout << "Permutations: ";
            for (int i = 0; i < 2 * n; i++) cout << arr[i] << " ";
            cout << endl;
        }
        else {
            cout << "Not possible" << endl;
        }
    }

    vector<int> multiplyExceptSelf(vector<int> arr) {
        int l = 1;
        int r = 1;
        vector<int> output(arr.size(), 1);
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            output[i] *= l;
            output[n - i - 1] *= r;
            l *= arr[i];
            r *= arr[n - i - 1];
        }
        // a: 2,3,1,4
        // l: 1, 2,6, 6
        // r: 12,4,4,1
        // o: 12,8,24,6
        return output;
    }
};