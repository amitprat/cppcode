#pragma once
#include "../Header.h"

// https://www.careercup.com/question?id=5713002834165760
class NecessarilyConnectedDirectedGraph
{
    class Graph {
        unordered_map<int, vector<int>> vertices;
    public:
        void add(int u, int v) {
            vertices[u].push_back(v);
        }

        string to_string()
        {
            stringstream ss;
            for (auto e : vertices)
            {
                ss << e.first << ":";
                for (auto u : e.second) ss << u << ",";
                ss << endl;
            }

            return ss.str();
        }

        vector<int> getNeighbours(int u) {
            return vertices[u];
        }
    };
public:
    static void test() {
        NecessarilyConnectedDirectedGraph obj;
        Graph g;
        g.add(0, 1);
        g.add(0, 2);
        g.add(1, 4);
        g.add(2, 4);
        g.add(2, 3);
        g.add(3, 5);
        g.add(4, 6);
        //g.add(5, 6);

        cout << g.to_string() << endl;

        unordered_set<int> visited;
        unordered_set<int> recStack;
        bool res = obj.isNecessarilyConnected(g, 0, 6, visited, recStack);
        cout << "Connected? " << res << endl;
    }

    bool isNecessarilyConnected(Graph g, int s, int e, unordered_set<int>& visited, unordered_set<int> recStack)
    {
        if (s == e) return true;
        visited.insert(s);
        recStack.insert(s);

        auto neighbours = getNeighbours(g, s);
        if (neighbours.empty()) return false;

        for (auto v : neighbours) {
            if (visited.find(v) == visited.end()) {
                if (!isNecessarilyConnected(g, v, e, visited, recStack)) return false;
            }
            else if (recStack.find(v) != recStack.end()) return false;
        }

        return true;
    }

    vector<int> getNeighbours(Graph g, int u)
    {
        return g.getNeighbours(u);
    }
};