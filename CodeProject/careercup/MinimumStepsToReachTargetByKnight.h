#pragma once
#include "../Header.h"

class MinimumStepsToReachTarget {
    struct Point {
        int x, y;
        bool operator ==(const Point& other) {
            return x == other.x && y == other.y;
        }
        Point operator +(const Point& other) {
            return { x + other.x,y + other.y };
        }
    };
    class Board {
    public:
        enum class Type {
            Empty,
            Pawn,
            Knight,
            Rook,
            Bishop,
            Queen,
            King
        };
        vector<vector<int>> board;
        unordered_map<Type, vector<Point>> movesMap;
        Board(int l, int w) {
            board.resize(l);
            for (int i = 0; i < l; i++) {
                board[i].resize(w);
                for (int j = 0; j < w; j++) {
                    board[i][j] = (int)Type::Empty;
                }
            }
            movesMap.insert({ Type::Knight,{{1,2},{2,1},{-1,2},{2,-1},{1,-2},{2,-1},{-1,-2},{-2,-1}} });
        }

        vector<Point> getNextPosSet(Point start, Type type) {
            vector<Point> result;
            if (movesMap.find(type) == movesMap.end()) return result;
            for (auto m : movesMap[type]) {
                auto n = start + m;
                if (isSafe(n)) result.push_back(n);
            }
            return result;
        }
        void set(Point target, Type type) {
            board[target.x][target.y] = (int)type;
        }
    private:
        bool isSafe(Point n) {
            return (n.x >= 0 && n.y >= 0 && n.x < board.size() && n.y < board[0].size()
                && board[n.x][n.y] == (int)Type::Empty);
        }
    };
public:
    static void test() {
        Point start = { 2,4 };
        Point end = { 6,4 };
        Board board(8, 8);

        MinimumStepsToReachTarget obj;
        cout << "Minimum Steps = " << obj.minSteps(board, start, end) << endl;
    }

    int minSteps(Board board, Point start, Point end) {
        queue<Point> q;
        q.push(start);
        int dist = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto front = q.front(); q.pop();
                if (front == end) return dist;
                for (auto n : board.getNextPosSet(front, Board::Type::Knight)) {
                    board.set(n, Board::Type::Knight);
                    q.push(n);
                }
            }
            dist++;
        }
    }
};