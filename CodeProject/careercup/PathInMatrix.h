#pragma once
#include "../Header.h"

class PathInMatrix {
public:
    static void test() {
        vector<vector<int>> matrix =
        { {1, 0, 0, 0},
            { 1, 1, 0, 0},
            {0, 1, 1, 0},
            {1, 1, 1, 1}
        };

        Point s = { 0,0 };
        Point e = { 3,3 };

        vector<Point> res = findPath(matrix, s, e);
        cout << to_string(res) << endl;
    }

    static vector<Point> findPath(vector<vector<int>> matrix, Point s, Point e) {
        if (matrix[s.x][s.y] == 0) return {};
        queue < pair<Point, vector<Point>>> q;
        q.push({ s, {s} });
        unordered_set<int> seen;
        int n = matrix.size();
        int m = matrix[0].size();
        seen.insert(s.x * m + s.y);

        while (!q.empty()) {
            auto u = q.front(); q.pop();
            if (u.first == e) return u.second;

            auto res = u.second;
            Point right = { u.first.x, u.first.y + 1 };
            Point down = { u.first.x + 1,u.first.y };

            if (right.y < m && matrix[right.x][right.y] && seen.find(right.x * m + right.y) == seen.end()) {
                res.push_back(right);
                q.push({ right, res });
                res.pop_back();
            }

            if (down.x < n && matrix[down.x][down.y] && seen.find(down.x * m + down.y) == seen.end()) {
                res.push_back(down);
                q.push({ down, res });
                res.pop_back();
            }
        }

        return {};
    }
};