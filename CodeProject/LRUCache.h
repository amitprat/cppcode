#pragma once

#include <time.h>
#include <stdlib.h>
#include <thread>
#include <vector>
#include <iostream>
#include <atomic> 
#include <mutex>
#include <time.h>
#include <fstream>
#include <stack>
#include <sstream> 
#include <unordered_map>
#include <unordered_set>
using namespace std;

template <class K, class V>
class LRUCache
{
    using E = pair<K, V>;
private:
    int capacity;
    list<E> dq;
    unordered_map<int, list<pair<int, int>>::iterator> map;

public:
    LRUCache(int capacity) : capacity(capacity) {}
    static void test()
    {
        int capacity = 5;
        LRUCache<int, int> lru(capacity);
        lru.put(1, 100);
        lru.put(2, 200);
        lru.put(3, 300);
        lru.put(4, 400);
        lru.put(5, 500);
        lru.put(6, 600);
        cout << "Value for key 1:" << lru.get(1) << endl;
        cout << "Value for key 2:" << lru.get(2) << endl;
        cout << "Value for key 3:" << lru.get(3) << endl;
        cout << "Value for key 5:" << lru.get(5) << endl;
        cout << "Value for key 6:" << lru.get(6) << endl;
        cout << "Value for key 7:" << lru.get(7) << endl;
        lru.put(3, 300);
        lru.put(4, 400);
        lru.put(5, 500);
        lru.put(6, 600);
        lru.put(1, 100);
        lru.put(7, 700);
        cout << "Value for key 1:" << lru.get(1) << endl;
        cout << "Value for key 2:" << lru.get(2) << endl;
        cout << "Value for key 3:" << lru.get(3) << endl;
        cout << "Value for key 4:" << lru.get(4) << endl;
        cout << "Value for key 5:" << lru.get(5) << endl;
        cout << "Value for key 6:" << lru.get(6) << endl;
        cout << "Value for key 7:" << lru.get(7) << endl;
    }

    void put(K key, V val)
    {
        cout << "Inserting: " << key << " " << val << endl;
        if (map.find(key) != map.end()) {
            cout << "Item already exists in cache" << endl;
            return;
        }

        if (map.size() == capacity) {
            map.erase(dq.back().first);
            dq.pop_back();
        }

        dq.push_front({ key, val });
        map[key] = dq.begin();
    }

    V get(K key)
    {
        cout << "Getting for key: " << key << endl;
        if (map.find(key) == map.end()) {
            cout << "Key doesn't exist in cache" << endl;
            return -1;
        }
        auto val = map[key]->second;
        dq.erase(map[key]);
        map.erase(key);

        dq.push_front({ key, val });
        map[key] = dq.begin();

        return val;
    }
};