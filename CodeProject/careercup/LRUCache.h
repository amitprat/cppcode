#pragma once
#include "../Header.h"

class LRUCache {
    struct PageFrame {
        int page, frame;
        PageFrame(int page, int frame) :page(page), frame(frame) {}
        string to_string() { return "(" + std::to_string(page) + "," + std::to_string(frame) + ")"; }
    };

    unordered_map<int, int> values = { {5,500}, {0,10}, {1,100}, {3,300}, {2,200}, {4,400}, {1,100}, {0,10}, {5,500} };

    int capacity = 0;
    list<PageFrame> dll;
    unordered_map<int, list<PageFrame>::iterator> map;

public:
    static void test() {
        LRUCache cache(10);
        vector<int> keys = { 5, 0, 1, 3, 2, 4, 1, 0, 5 };

        for (auto key : keys) {
            auto v = cache.get(key);
            cout << "Fetched " << key << " = " << v << endl;
        }
    }

    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (map.find(key) != map.end()) {
            cout << "[CacheHit]" << "Key " << key << " already exists in cache, moving it to front" << endl;
            moveToFront(key);

            return map[key]->frame;
        }

        cout << "[CacheMiss]";
        if (isfull()) {
            removeFromEnd();
        }

        insertAtFront(key);
    }

    void moveToFront(int key) {
        auto v = map[key];
        dll.insert(dll.begin(), *v);
        dll.erase(v);
        map[key] = dll.begin();
    }

    bool isfull() {
        return map.size() == capacity;
    }

    void removeFromEnd() {
        auto v = dll.back(); dll.pop_back();
        cout << "Cache is full, removing last pageframe " << v.to_string() << endl;
        map.erase(v.page);
    }

    void insertAtFront(int key) {
        auto val = values[key];
        dll.push_front(PageFrame(key, val));
        cout << "Inserting " << key << "," << val << " to front." << endl;

        map.insert({ key, dll.begin() });
    }
};