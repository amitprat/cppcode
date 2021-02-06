#pragma once
#include "../Header.h"

class NameMapping {
    class Graph {
    public:
        unordered_map<string, unordered_set<string>> vertices;
        void addEdge(string s, string e) {
            vertices[s].insert(e);
        }
    };
public:
    static void test() {
        NameMapping obj;
        unordered_map<string, int> freqMap = { {"John",10 },{ "Jon",3}, {"Davis",2}, {"Kari",3},{"Johnny",11},
            {"Carlton",8},{"Carleton",2},{"Jonathan",9},{"Carrie",5} };
        vector<pair<string, string>> nameMap = { {"Jonathan","John"},{"Jon","Johnny"},{"Johnny","John"},{"Kari","Carrie"}, {"Carleton","Carlton"} };

        auto res = obj.getNameMap(freqMap, nameMap);
        for (auto e : res) {
            cout << e.first << ":" << e.second << endl;
        }
        cout << endl;
    }

    unordered_map<string, int> getNameMap(unordered_map<string, int> freqMap,
        vector<pair<string, string>> nameMap) {
        Graph g = constructGraph(nameMap);
        unordered_map<string, string> revMap = getTrueMap(g);

        unordered_map<string, int> result;
        for (auto f : freqMap) {
            auto key = (revMap.find(f.first) != revMap.end()) ? revMap[f.first] : f.first;
            result[key] += f.second;
        }

        return result;
    }

private:
    Graph constructGraph(vector<pair<string, string>> nameMap) {
        Graph g;
        for (auto entry : nameMap) {
            g.addEdge(entry.second, entry.first);
        }
        return g;
    }

    unordered_map<string, string> getTrueMap(Graph g) {
        unordered_map<string, string> result;
        unordered_set<string> visited;
        for (auto v : g.vertices) {
            if (visited.find(v.first) == visited.end()) {
                dfs(v.first, v.first, g, result, visited);
            }
        }

        return result;
    }

    void dfs(string u, string v, Graph g, unordered_map<string, string>& result,
        unordered_set<string>& visited) {
        visited.insert(v);
        if (u != v) result[v] = u;

        for (auto w : g.vertices[v]) {
            if (visited.find(w) == visited.end()) {
                dfs(u, w, g, result, visited);
            }
        }
    }
};