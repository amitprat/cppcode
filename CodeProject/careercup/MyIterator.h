#pragma once
#include "../Header.h"

class MyIterator {
    class MyIteratorImpl {
        vector<vector<int>> input;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    public:
        MyIteratorImpl(vector<vector<int>> input) :input(input) {
            for (int i = 0; i < input.size(); i++) {
                if (!input[i].empty()) pq.push({ input[i][0],{i,0} });
            }
        }

        bool hasNext() {
            return !pq.empty();
        }

        int next() {
            auto item = pq.top(); pq.pop();
            if (input[item.second.first].size() > item.second.second + 1) {
                pq.push({ input[item.second.first][item.second.second + 1],{item.second.first, item.second.second + 1} });
            }

            return item.first;
        }
    };

public:
    static void test() {
        vector<vector<int>> input = { {1, 5, 7},{2, 3, 10},{4, 6, 9 } };

        MyIteratorImpl obj(input);
        while (obj.hasNext()) {
            cout << obj.next() << " ";
        }
    }
};