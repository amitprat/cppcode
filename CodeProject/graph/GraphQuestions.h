#pragma once

#include <time.h>
#include <stdlib.h>
#include <thread>
#include <vector>
#include <iostream>
#include <atomic>
#include <unordered_set>
#include <time.h>
#include <fstream>
#include <tuple>
#include <queue>
#include <unordered_map>
#include <string>
#include <sstream>
#include <map>
using namespace std;

template <class T>
class Graph
{
public:
    using VertexId = T;
    using AdjList = vector<VertexId>;

private:
    unordered_map<VertexId, AdjList> vertices;

public:
    bool add(VertexId vertex) {
        if (vertices.find(vertex) != vertices.end()) {
            return false;
        }
        vertices.insert({ vertex, {} });
        return true;
    }

    bool addEdge(VertexId src, VertexId dst) {
        if (vertices.find(src) == vertices.end() || vertices.find(dst) == vertices.end()) return false;
        vertices[src].push_back(dst);
        return true;
    }

    vector<VertexId> bfs(VertexId start) {
        vector<VertexId> result;
        queue<VertexId> q;
        q.push(start);
        unordered_set<VertexId> visited;
        visited.insert(start);

        while (!q.empty()) {
            auto u = q.front(); q.pop();
            result.push_back(u);
            for (auto v : vertices[u]) {
                if (visited.find(v) == visited.end()) {
                    visited.insert(v);
                    q.push(v);
                }
            }
        }

        return result;
    }

    vector<VertexId> dfs(VertexId start) {
        unordered_set<VertexId> visited;
        vector<VertexId> result;
        dfsUtil(start, visited, result);

        return result;
    }

    int shortestDistance(VertexId src, VertexId dst) {
        queue<VertexId> q;
        q.push(src);
        unordered_set<VertexId> visited;
        int dist = 0;

        while (!q.empty()) {
            auto u = q.front(); q.pop();
            if (u == dst) return dist;

            dist++;
            for (auto v : vertices[u]) {
                if (visited.find(v) == visited.end()) {
                    q.push(v);
                }
            }
        }

        return dist;
    }

    string str() {
        unordered_set<VertexId> visited;
        string result;
        for (auto u : vertices) {
            if (visited.find(u.first) == visited.end()) {
                result += "[" + to_string(u.first) + "=> ";
                for (auto v : u.second) {
                    result += to_string(v) + " ";
                }
                result += "], ";
            }
        }
        return result;
    }

private:
    void dfsUtil(VertexId start, unordered_set<VertexId>& visited, vector<VertexId>& result) {
        result.push_back(start);
        visited.insert(start);

        for (auto v : vertices[start]) {
            if (visited.find(v) == visited.end()) {
                dfsUtil(v, visited, result);
            }
        }
    }
};

class GraphQuestions {
public:
    static void test() {
        Graph<uint64_t> g;
        g.add(1);
        g.add(2);
        g.add(4);
        g.add(3);
        g.addEdge(2, 4);
        g.addEdge(2, 1);
        g.addEdge(4, 1);
        g.addEdge(4, 3);
        g.addEdge(1, 3);
        g.addEdge(3, 1);
        g.addEdge(1, 2);
        g.addEdge(3, 2);
        g.addEdge(3, 4);
        cout << g.str() << endl;

        cout << "BFS : ";
        auto res = g.bfs(3);
        for (auto i : res) cout << i << " ";
        cout << endl;

        cout << "DFS : ";
        res = g.dfs(3);
        for (auto i : res) cout << i << " ";
        cout << endl;

        uint64_t src = 3, dst = 1;
        cout << "Shortest distance between src=" << src << " and dst=" << dst << " : ";;
        auto dist = g.shortestDistance(src, dst);
        cout << dist << endl;
    }
};