#include <stdlib.h>
#include <thread>
#include <vector>
#include <iostream>
#include <atomic>
#include <mutex>
#include <time.h>
#include <fstream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

const int N = 5;
class CountPath
{
public:
    using Point = pair<int, int>;
    const vector<Point> nb = { {-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1} };
    static void test()
    {
        CountPath obj;
        bool matrix[N][N] = {
            {1,0,1,1,1},
            {0,1,0,1,1},
            {0,0,1,1,1},
            {1,0,1,0,1},
            {0,1,1,1,1}
        };

        auto res = obj.getPath(matrix, N, { 0,0 }, { 4,4 });
        for (auto i : res) {
            cout << "{" << i.first << ", " << i.second << "}, ";
        }
        cout << endl;
    }

    struct hash_pair {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const
        {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
            return hash1 ^ hash2;
        }
    };

    vector<Point> getPath(bool matrix[][N], int N, Point start, Point end)
    {
        vector<Point> result;
        unordered_set <Point, hash_pair> set;

        queue<pair<Point, vector<Point>>> q;
        q.push({ start, {start} });
        set.insert(start);

        while (!q.empty()) {
            auto u = q.front(); q.pop();
            if (u.first == end) return u.second;
            for (auto v : getChildren(u.first)) {
                if (set.find(v) == set.end() && matrix[v.first][v.second] == 1) {
                    auto p = u.second;
                    p.push_back(v);
                    q.push({ v, p });
                    set.insert(v);
                }
            }
        }

        return {};
    }

    vector<Point> getChildren(Point u)
    {
        vector<Point> res;
        for (auto n : nb) {
            Point  p = { u.first + n.first, u.second + n.second };
            if (valid(p)) res.push_back(p);
        }

        return res;
    }

    bool valid(Point p) {
        return p.first >= 0 && p.second >= 0 && p.first < N&& p.second < N;
    }
};