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
#include <sstream>
#include <unordered_map>
#include <fstream>
using namespace std;

class UnionFind
{
private:
    int* indx;
    int sz = 0;
    int* rank;

public:
    UnionFind(int sz)
    {
        indx = new int[sz];
        rank = new int[sz];
        this->sz = sz;
        for (int i = 0; i < sz; i++) {
            indx[i] = i;
            rank[i] = 0;
        }
    }

    int find(int p)
    {
        while (p != indx[p]) p = indx[p];

        return p;
    }

    void Union(int a, int b)
    {
        int aRoot = find(a);
        int bRoot = find(b);
        if (aRoot != bRoot)
        {
            if (rank[aRoot] < rank[bRoot]) {
                indx[aRoot] = bRoot;
            }
            else if (rank[aRoot] < rank[bRoot]) {
                indx[aRoot] = bRoot;
            }
            else {
                indx[aRoot] = bRoot;
                rank[aRoot]++;
            }
        }
    }

    bool Connected(int a, int b)
    {
        return find(a) == find(b);
    }

    string toString(int n)
    {
        stringstream ss;
        for (int i = 0; i < sz; i++) {
            ss << "{" << indx[i] / n << "," << indx[i] % n << "} ";
        }

        return ss.str();
    }
};
class CountNumberOfIslands
{
public:
    static void test()
    {
        {
            CountNumberOfIslands obj;
            UnionFind* uf;
            vector<vector<int>> board = {
                {1, 1, 0, 0, 0},
                {0, 1, 0, 0, 1},
                {1, 0, 0, 1, 1},
                {0, 0, 0, 0, 0},
                {1, 0, 1, 0, 1}
            };
            int n = board.size();
            int m = board[0].size();

            uf = new UnionFind(n * m);
            auto res = obj.countIslands(board, uf, n, m);
            cout << "Islands = " << res << endl;
        }
        {
            cout << "----------------------------" << endl;
            ifstream in;
            in.open("input.txt");
            CountNumberOfIslands obj;
            UnionFind* uf = new UnionFind(25);

            auto res = obj.countIslands(in, uf);
            cout << "Islands = " << res << endl;
        }
    }

    vector<int> split(string str)
    {
        vector<int> res;
        size_t pos = string::npos;
        int start = 0;
        do {
            pos = str.find(' ');
            string tmp = str.substr(start, pos);
            res.push_back(stoi(tmp));
            if (pos != string::npos) str = str.substr(pos + 1);
        } while (pos != string::npos);

        return res;
    }

    int countIslands(ifstream& in, UnionFind* uf)
    {
        string line;
        int rowNum = 0;
        vector<int> prevRow;
        int islands = 0;
        while (getline(in, line))
        {
            vector<int> row = split(line);
            int rowSize = row.size();
            for (int j = 0; j < rowSize; j++)
            {
                int k = rowNum * rowSize;
                if (row[j] == 1) {
                    bool isNewIsland = true;
                    if (j - 1 >= 0 && row[j - 1] == 1) {
                        uf->Union(k, rowNum * rowSize + j - 1); isNewIsland = false;
                    }
                    if (prevRow.size())
                    {
                        if (j - 1 >= 0 && prevRow[j - 1] == 1) {
                            uf->Union(k, rowSize * (rowNum - 1) + j - 1);
                            isNewIsland = false;
                        }
                        if (prevRow[j] == 1) {
                            uf->Union(k, rowSize * (rowNum - 1) + j);
                            isNewIsland = false;
                        }
                        if (j + 1 < rowSize && prevRow[j + 1] == 1) {
                            uf->Union(k, rowSize * (rowNum - 1) + j + 1);
                            isNewIsland = false;
                        }
                    }
                    if (isNewIsland) {
                        islands++;
                    }
                }
            }
            prevRow = row;
            rowNum++;
        }
        //cout << uf->toString(prevRow.size());

        return islands;
    }

    int countIslands(vector<vector<int>> board, UnionFind* uf, int n, int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int k = i * n + j;
                if (board[i][j] == 1)
                {
                    if (j - 1 >= 0 && board[i][j - 1] == 1) uf->Union(k, i * n + j - 1);
                    if (i - 1 >= 0 && board[i - 1][j] == 1) uf->Union(k, (i - 1) * n + j);
                    if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == 1) uf->Union(k, (i - 1) * n + j - 1);
                    if (i - 1 >= 0 && j + 1 < m && board[i - 1][j + 1] == 1) uf->Union(k, (i - 1) * n + j + 1);
                }
            }
        }

        int islands = 0;
        int* parent = new int[n * m];
        memset(parent, 0, n * m * sizeof(int));
        unordered_map<int, vector<pair<int, int>>> islandsList;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 1)
                {
                    int x = uf->find(i * n + j);
                    if (parent[x] == 0) {
                        islands++;
                    }
                    islandsList[x].push_back({ i,j });
                    parent[x]++;
                }
            }
        }

        cout << "[";
        for (auto i : islandsList) {
            cout << "{";
            for (auto j : i.second) {
                cout << "(" << j.first << ", " << j.second << "), ";
            }
            cout << "}, ";
        }
        cout << "]";

        return islands;
    }
};