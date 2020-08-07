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

class Edge
{
public:
    int s, d, w;
    Edge(int s, int d, int w) :s(s), d(d), w(w) {}
};
class Graph
{
public:
    int V;
    vector<vector<Edge>> nodes;

public:
    Graph(int v) : V(v) { nodes.resize(V); }
    void addEdge(int s, int d, int w) {
        nodes[s].push_back(Edge(s, d, w));
    }
    Graph(vector<tuple<int, int, int>> v)
    {
        V = v.size();
        nodes.resize(V);
        for (auto i : v) {
            nodes[get<0>(i)].push_back(Edge(get<0>(i), get<1>(i), get<2>(i)));
        }
    }
};

class Node
{
public:
    int d;
    int w;
    Node() {}
    Node(int d, int w) : d(d), w(w) {}
};

template <class T>
class Minheap
{
private:
    vector<T> nodes;
    vector<int> pos;
    int sz = 0;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void upHeapify(int c)
    {
        int p = parent(c);
        while (c != 0 && nodes[p] > nodes[c])
        {
            swap(nodes[p], nodes[c]);
            swap(pos[p], pos[c]);
            c = p;
            p = parent(c);
        }
    }

    void downHeapify(int i)
    {
        int smallest = i;
        int l = left(i);
        if (l < sz && nodes[l] < nodes[smallest]) smallest = l;

        int r = right(i);
        if (r < sz && nodes[r] < nodes[smallest]) smallest = r;

        if (smallest != i)
        {
            swap(nodes[i], nodes[smallest]);
            swap(pos[i], pos[smallest]);
            downHeapify(smallest);
        }
    }

public:
    Minheap(int v)
    {
        sz = v;
        nodes.resize(sz);
        pos.resize(sz);
    }

    void add(int key, int val)
    {
        nodes[pos[key]] = val;
    }

    void build()
    {
        for (int i = sz / 2 - 1; i >= 0; i--) {
            downHeapify(i);
        }
    }

    pair<int, int> pop()
    {
        int top = nodes.front();
        nodes[0] = nodes[sz - 1];
        sz--;
        nodes.pop_back();
        downHeapify(0);

        return { pos[0],top };
    }
    bool empty() { return sz == 0; }
    int size() { return sz; }
    int weight(int i) { return nodes[pos[i]]; }
    void decreaseKey(int k, int w)
    {
        nodes[pos[k]] = w;
        upHeapify(pos[k]);
    }
};

class PrimsAdj
{
public:
    void test()
    {
        vector<Graph> graphs = {
            Graph({{0,1,4}, {0,7,8},{1,2,8},{1,7,11},{2,3,7},{2,8,2},{2,5,4},{3,4,9},{3,5,14},{4,5,10},{5,6,2},{6,7,1},{6,8,6},{7,8,7}})
        };

        for (auto graph : graphs) {
            findMst(graph);
        }
    }

    void findMst(Graph g)
    {
        Minheap<int> heap(g.V);
        int src = 0;
        bool* visited = new bool[g.V];
        int* parent = new int[g.V];
        parent[src] = -1;
        heap.add(src, 0);

        for (int i = 1; i < g.V; i++) {
            visited[i] = false;
            heap.add(i, INT_MAX);
        }
        heap.build();

        while (!heap.empty())
        {
            pair<int, int> minWtVertex = heap.pop();
            cout << "Processing vertx: " << minWtVertex.first << endl;
            visited[minWtVertex.first] = true;
            cout << parent[minWtVertex.first] << "->" << minWtVertex.first << endl;

            for (auto child : g.nodes[minWtVertex.first]) {
                if (!visited[child.d]) {
                    if (heap.weight(child.d) > child.w) {
                        heap.decreaseKey(child.d, child.w);
                        parent[child.d] = minWtVertex.first;
                        cout << "Processing children: " << child.d << endl;
                    }
                }
            }
        }

        //printMst(visited, parent, g);
    }

    void printMst(bool visited[], int parent[], Graph g)
    {
        cout << "{";
        for (int i = 1; i < g.V; i++) {
            if (visited[i])
            {
                cout << "(" << parent[i] << "->" << i << ":" << g.nodes[parent[i]][i].w << ")";
                cout << " ";
            }
        }
        cout << "}";
    }
};