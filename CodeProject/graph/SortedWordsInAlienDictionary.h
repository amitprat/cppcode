#pragma once
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
#include <bitset>
#include <string>
#include <functional>
#include <future>
#include "AsyncState.h"
using namespace std;

template <class T>
class Graph
{
private:
    using AdjList = unordered_map<T, vector<T>>;
    AdjList adjList;

public:
    int size() { return adjList.size(); }
    vector<T> vertices() {
        vector<T> v;
        for (auto i : adjList) {
            v.push_back(i.first);
        }
        return v;
    }
    void addEdge(T from, T to)
    {
        adjList[from].push_back(to);
    }

    vector<T> topoSort()
    {
        vector<T> res;
        unordered_set<T> visited;
        for (auto v : adjList) {
            if (visited.find(v.first) == visited.end()) {
                dfs(v.first, visited, res);
            }
        }

        return res;
    }

    void dfs(T u, unordered_set<T>& visited, vector<T>& res)
    {
        visited.insert(u);
        for (auto v : adjList[u]) {
            if (visited.find(v) == visited.end()) {
                dfs(v, visited, res);
            }
        }
        res.insert(res.begin(), u);
    }
};

class SortedWordsInAlienDictionary
{
public:
    static void test()
    {
        SortedWordsInAlienDictionary obj;
        vector<string> words = { "cc", "cb", "bb", "ac" };
        vector<char> order = obj.findOrdering(words);
        for (auto ch : order) {
            cout << ch << " ";
        }
        cout << endl;
    }

    vector<char> findOrdering(vector<string> words)
    {
        Graph<char> g;
        for (int i = 0; i < words.size() - 1; i++) {
            string f = words[i];
            string s = words[i + 1];
            int fl = f.length();
            int sl = s.length();
            for (int j = 0; j < min(fl, sl); j++) {
                if (f[j] == s[j]) continue;
                g.addEdge(f[j], s[j]);
                break;
            }
        }

        return g.topoSort();
    }
};