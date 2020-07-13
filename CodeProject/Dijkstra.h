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

struct Node
{
    int s, d, w;
};
class Graph
{
public:
    int V;
    vector<list<Node>> nodes;
    Graph(vector<Node> nodes)
    {
        V = nodes.size();
        this->nodes.resize(V);
        for (auto node : nodes)
        {
            this->nodes[node.s].push_back(node);
        }
    }
};

class Minheap
{
private:
    vector<int> nodes;
    vector<int> pos;
    int sz = 0;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int index(int i) { return pos[i]; }
    void swapPos(int i, int j) {
        int tmp = pos[i];
        pos[i] = pos[j];
        pos[j] = tmp;
    }

    void upHeapify(int c)
    {
        int p = parent(c);
        while (c != 0 && nodes[p] > nodes[c])
        {
            swap(nodes[p], nodes[c]);
            swapPos(p, c);
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
            swapPos(i, smallest);
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
        nodes[key] = val;
        pos[key] = key;
    }

    void build()
    {
        int end = sz / 2 - 1;
        for (int i = end; i >= 0; i--)
        {
            downHeapify(i);
        }
    }

    pair<int, int> pop()
    {
        int top = nodes.front();
        nodes[0] = nodes[sz - 1];
        int ind = index(0);
        pos[0] = pos[sz - 1];

        sz--;

        nodes.pop_back();
        pos.pop_back();

        downHeapify(0);

        return { ind, top };
    }
    bool empty() { return sz == 0; }
    int size() { return sz; }
    int weight(int i) {
        int idx = index(i);
        cout << "idx:" << idx << endl;
        return nodes[idx];
    }
    void decreaseKey(int k, int w)
    {
        int idx = index(k);
        nodes[idx] = w;
        upHeapify(idx);
    }
    bool isInMinheap(int v)
    {
        return pos.size() > v && pos[v] < sz;
    }

    static void test()
    {
        Minheap heap(3);
        heap.add(0, 5);
        heap.add(1, 2);
        heap.add(2, 3);
        heap.build();
        heap.decreaseKey(0, 1);

        while (!heap.empty()) {
            auto res = heap.pop();
            cout << res.first << " " << res.second << endl;
        }
    }
};

class Dijkstra
{
public:
    void test()
    {
        vector<Graph> graphs = {
            Graph({{0,1,10}, {1,2,30},{0,2,5},{2,3,7},{1,3,9}})
        };
        for (auto g : graphs)
        {
            int src = 0;
            dijkstra(src, g);
        }
    }

    void dijkstra(int src, Graph g)
    {
        Minheap heap(g.V);
        int* key = new int[g.V];
        for (int i = 0; i < g.V; i++) {
            key[i] = INT_MAX;
            heap.add(i, key[i]);
        }
        heap.build();
        key[src] = 0;
        heap.decreaseKey(src, 0);

        while (!heap.empty())
        {
            auto vertex = heap.pop();

            for (auto child : g.nodes[vertex.first])
            {
                if (heap.isInMinheap(child.d) && key[vertex.first] != INT_MAX && key[vertex.first] + child.w < key[child.d])
                {
                    key[child.d] = key[vertex.first] + child.w;
                    heap.decreaseKey(child.d, key[child.d]);
                }
            }
        }

        printArr(key, g.V);
    }

    void printArr(int dist[], int n)
    {
        cout << "Vertex   Distance from Source\n";
        for (int i = 0; i < n; ++i)
            cout << i << " " << dist[i] << endl;
    }
};