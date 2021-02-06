#pragma once
#include "../Header.h"

class PrimsMST {
public:
    static void test() {
        PrimsMST obj;
        vector<vector<int>> g = {
            { 0, 2, 0, 6, 0 },
            { 2, 0, 3, 8, 5 },
            { 0, 3, 0, 0, 7 },
            { 6, 8, 0, 0, 9 },
            { 0, 5, 7, 9, 0 }
        };

        auto res = obj.mst(g);
        for (int v = 1; v < g.size(); v++) {
            auto u = res[v].second;
            cout << u << "-->" << v << " = " << res[v].first << endl;
        }
    }

    vector<pair<int, int>> mst(vector<vector<int>> g) {
        vector<pair<int, int>> dst(g.size(), { INT_MAX,-1 });
        vector<bool> visited(g.size(), false);
        dst[0] = { 0,-1 };

        for (int cnt = 0; cnt < g.size() - 1; cnt++) {
            int u = minVertex(dst, visited);
            visited[u] = true;
            for (int v = 0; v < g.size(); v++) {
                if (g[u][v] && !visited[v]) {
                    if (g[u][v] < dst[v].first) {
                        dst[v] = { g[u][v],u };
                    }
                }
            }
        }

        return dst;
    }

private:
    int minVertex(vector<pair<int, int>> dst, vector<bool> visited) {
        int mn = INT_MAX;
        int mnIndex = -1;
        for (auto i = 0; i < dst.size(); i++) {
            if (!visited[i] && dst[i].first < mn) {
                mn = dst[i].first;
                mnIndex = i;
            }
        }
        return mnIndex;
    }
};

class PrimsMSTAdj {
    struct Graph {
        int V;
        Graph(int v) :V(v) {}
        struct Edge {
            int v, w;
        };
        unordered_map<int, vector<Edge>> edges;
        void addEdge(int u, int v, int w) {
            edges[u].push_back({ v,w });
            edges[v].push_back({ u,w });
        }
    };
    class Minheap {
        vector<pair<int, int>> arr;
        unordered_map<int, int> positions;
    public:
        void put(pair<int, int> u) {
            if (exits(u))  update(u);
            else insert(u);
        }
        int size() { return arr.size(); }
        pair<int, int> pop() {
            auto res = arr[0];
            arr[0] = arr[arr.size() - 1];
            positions[arr[0].first] = 0;
            positions.erase(res.first);
            arr.pop_back();
            downHeapify(0);

            return res;
        }

        int get(int u) {
            return arr[positions[u]].second;
        }
        bool contains(int u) {
            return positions.find(u) != positions.end();
        }
    private:
        bool exits(pair<int, int> u) { return positions.find(u.first) != positions.end(); }
        void update(pair<int, int> u) {
            int p = positions[u.first];
            arr[p] = u;
            positions[u.first] = p;
            if (u.second > arr[p].second) downHeapify(p);
            else upHeapify(p);
        }
        void insert(pair<int, int> u) {
            arr.push_back(u);
            positions[u.first] = arr.size() - 1;
            upHeapify(arr.size() - 1);
        }
        void downHeapify(int p) {
            int mn = p;
            int lp = left(p);
            if (lp < arr.size() && arr[lp].second < arr[mn].second) { mn = lp; }
            int rp = right(p);
            if (rp < arr.size() && arr[rp].second < arr[mn].second) { mn = rp; }

            if (mn != p) {
                swap(arr[mn], arr[p]);
                swap(positions[arr[mn].first], positions[arr[p].first]);
                downHeapify(mn);
            }
        }
        void upHeapify(int u) {
            int p = parent(u);
            while (u != 0 && arr[p].second > arr[u].second) {
                swap(arr[p], arr[u]);
                swap(positions[arr[p].first], positions[arr[u].first]);
                u = p;
                p = parent(u);
            }
        }
        int parent(int u) {
            return (u - 1) / 2;
        }
        int left(int u) {
            return 2 * u + 1;
        }
        int right(int u) {
            return 2 * u + 2;
        }
    };
public:
    static void test() {
        PrimsMSTAdj obj;
        Graph g(9);
        g.addEdge(0, 1, 4);
        g.addEdge(0, 7, 8);
        g.addEdge(1, 2, 8);
        g.addEdge(1, 7, 11);
        g.addEdge(2, 3, 7);
        g.addEdge(2, 8, 2);
        g.addEdge(2, 5, 4);
        g.addEdge(3, 4, 9);
        g.addEdge(3, 5, 14);
        g.addEdge(4, 5, 10);
        g.addEdge(5, 6, 2);
        g.addEdge(6, 7, 1);
        g.addEdge(6, 8, 6);
        g.addEdge(7, 8, 7);

        auto res = obj.mst(g);
        for (int v = 1; v < g.V; v++) {
            auto u = res[v].second;
            cout << u << "-->" << v << " = " << res[v].first << endl;
        }
    }

    vector<pair<int, int>> mst(Graph g) {
        vector<pair<int, int>> result(g.V, { INT_MAX,-1 });
        result[0] = { 0,-1 };
        Minheap mh;
        for (int i = 0; i < g.V; i++) {
            mh.put({ i,INT_MAX });
        }
        mh.put({ 0,0 });

        while (mh.size() != 0) {
            auto u = mh.pop();
            for (auto e : g.edges[u.first]) {
                if (mh.contains(e.v)) {
                    if (e.w < result[e.v].first) {
                        result[e.v] = { e.w,u.first };
                        mh.put({ e.v, e.w });
                    }
                }
            }
        }

        return result;
    }
};

class KrushkalsMST {
    struct Edge {
        int u, v, w;
    };
    struct Graph {
        int V;
        vector<Edge> edges;
        Graph(int v) :V(v) {}
        void addEdge(int u, int v, int w) {
            edges.push_back({ u,v,w });
            edges.push_back({ v,u,w });
        }
    };
    struct UnionFind {
        vector<int> arr;
        vector<int> rank;
        UnionFind(int sz) {
            arr.resize(sz);
            rank.resize(sz);
            for (int i = 0; i < sz; i++) {
                arr[i] = i;
                rank[i] = 0;
            }
        }
        int find(int p) {
            while (arr[p] != p) {
                p = arr[p];
            }
            return p;
        }
        void Union(int p, int q) {
            auto pRoot = find(p);
            auto qRoot = find(q);
            if (rank[pRoot] < rank[qRoot]) {
                arr[pRoot] = qRoot;
            }
            else if (rank[qRoot] < rank[pRoot]) {
                arr[qRoot] = pRoot;
            }
            else {
                arr[pRoot] = qRoot;
                rank[qRoot]++;
            }
        }

        bool connected(int p, int q) {
            return find(p) == find(q);
        }
    };
public:
    static void test() {
        KrushkalsMST obj;
        Graph g(4);
        g.addEdge(0, 1, 10);
        g.addEdge(0, 2, 6);
        g.addEdge(0, 3, 5);
        g.addEdge(1, 3, 15);
        g.addEdge(2, 3, 4);

        vector<Edge> edges = obj.mst(g);
        for (auto e : edges) {
            cout << e.u << "-->" << e.v << ":" << e.w << endl;
        }
    }

    vector<Edge> mst(Graph g) {
        sort(g.edges.begin(), g.edges.end(), [](auto f, auto s) {return f.w < s.w; });
        vector<Edge> edges;
        UnionFind uf(g.V);
        int e = 0;
        while (edges.size() < g.V - 1 && e < g.edges.size()) {
            auto edge = g.edges[e++]; // pick first edge
            if (!uf.connected(edge.u, edge.v)) {
                edges.push_back(edge);
                uf.Union(edge.u, edge.v);
            }
        }

        return edges;
    }
};