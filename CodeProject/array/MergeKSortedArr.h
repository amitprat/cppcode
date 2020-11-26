#pragma once
#include "../header.h"

template <class T, class C>
class PriorityQueue {
private:
    vector<T> container;
    C comparator;
    int capacity;
public:
    PriorityQueue(C comparator, int capacity) : comparator(comparator), capacity(capacity) {}
    void push(T item) {
        container.push_back(item);

        upHeapify(container.size() - 1);
    }
    T top() {
        if (container.empty()) throw exception("Empty");
        return container.front();
    }
    T pop() {
        if (container.empty()) throw exception("Empty");
        auto item = container[0];
        container[0] = container[container.size() - 1];
        container.pop_back();

        downHeapify(0);

        return item;
    }
    bool isFull() {
        return container.size() == capacity;
    }
    bool empty() {
        return container.empty();
    }

private:
    void upHeapify(int idx) {
        auto p = parent(idx);
        while (idx > 0 && container[p] > container[idx]) {
            swap(container[p], container[idx]);
            idx = p;
            p = parent(idx);
        }
    }
    void downHeapify(int idx) {
        int sm = idx;
        int  l = left(idx);
        if (l < container.size() && container[l] < container[idx]) sm = l;

        int r = right(idx);
        if (r < container.size() && container[r] < container[idx]) sm = r;

        if (sm != idx) {
            swap(container[idx], container[sm]);
            downHeapify(sm);
        }
    }

    int left(int i) { return 2 * i + 1; }

    int right(int i) { return 2 * i + 2; }

    int parent(int i) { return (i - 1) / 2; }
};
class MergeKSortedArr {
public:
    static void test() {
        MergeKSortedArr obj;

        cout << "Original Arrays:" << endl;
        vector<vector<int>> arr = { {2, 6, 12, 34},
                  {1, 9, 20, 1000},
                  {23, 34, 90, 2000} };
        print(arr);
        int k = 3;

        vector<int> output = obj.merge(arr, k);

        cout << "Merged array is " << endl;
        print(output);
    }

    vector<int> merge(vector<vector<int>>& arr, int k) {
        auto Comparator = [](auto f, auto s) {return f < s; };
        PriorityQueue<int, decltype(Comparator)> pq(Comparator, k);
        vector<int> result;

        for (int i = 0;; i++) {
            bool res = false;
            for (auto a : arr) {
                if (a.size() > i) {
                    res = true;
                    if (pq.isFull()) {
                        result.push_back(pq.pop());
                    }
                    pq.push(a[i]);
                }
            }
            if (res == false) break;
        }

        while (!pq.empty()) {
            result.push_back(pq.pop());
        }

        return result;
    }
};