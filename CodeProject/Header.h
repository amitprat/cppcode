#pragma once
#include <time.h>
#include <stdlib.h>
#include <thread>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <time.h>
#include <stack>
#include <string>
#include <chrono>
#include <tuple>
#include <queue>
#include <sstream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <iomanip>
#include <random>
#include <any>
#include <future>
#include <shared_mutex>
#include <map>
#include <exception>
#include <bitset>
#include <numeric>
#include "prettyprint.h"
using namespace std;

using CBoard = vector<vector<char>>;
using IBoard = vector<vector<int>>;

class Interval {
public:
    int start;
    int end;
    Interval() :start(INT_MAX), end(INT_MIN) {}
    Interval(int start, int end) : start(start), end(end) {}
    string to_string() {
        return "{" + std::to_string(start) + "," + std::to_string(end) + "}";
    }

    bool operator < (Interval other) {
        return end < other.start;
    }

    bool operator > (Interval other) {
        return start > other.end;
    }

    bool overlap(Interval other) {
        return !(*this < other || *this > other);
    }
};

class Point {
public:
    int x, y;
    Point() :x(0), y(0) {}
    Point(int x, int y) :x(x), y(y) {}
    Point operator +(const Point& other) {
        Point result(x + other.x, y + other.y);
        return result;
    }
    string to_string() {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    bool operator ==(const Point& other) {
        return x == other.x && y == other.y;
    }
};

string to_string(vector<Interval>& input) {
    stringstream ss;
    ss << "[";
    for (auto& i : input) ss << i.to_string() << ", ";
    ss.seekp(-2, std::ios_base::end);
    ss << "]";
    return ss.str();
}

template <typename T>
string to_string(vector<T>& input) {
    stringstream ss;
    ss << "[";
    for (auto& i : input) ss << std::to_string(i) << ", ";
    if (ss.str().size() > 2) { ss.seekp(-2, std::ios_base::end); }
    ss << "]";
    return ss.str();
}

string to_string(vector<char>& input) {
    stringstream ss;
    ss << "[";
    for (auto& i : input) ss << i << ", ";
    ss.seekp(-2, std::ios_base::end);
    ss << "]";
    return ss.str();
}

string to_string(vector<string>& input) {
    stringstream ss;
    ss << "[";
    for (auto& i : input) ss << i << ", ";
    ss.seekp(-2, std::ios_base::end);
    ss << "]";
    return ss.str();
}

template <typename T, typename U>
string to_string(vector<pair<T, U>> input) {
    stringstream ss;
    ss << "[";
    for (auto& i : input) ss << "{" << i.first << ", " << i.second << "}" << ", ";
    ss.seekp(-2, std::ios_base::end);
    ss << "]";
    return ss.str();
}

template <typename T>
string to_string(vector<vector<T>> input) {
    stringstream ss;
    ss << "[";
    ss << endl;
    for (int i = 0; i < input.size(); i++) {
        bool added = false;
        ss << setw(4);
        ss << "{";
        for (auto& j : input[i]) {
            ss << j << ", ";
            added = true;
        }
        if (!added) ss.seekp(-2, std::ios_base::end);
        ss << "}";
        ss << endl;
    }
    ss << "]";
    return ss.str();
}

string to_sudoku_string(IBoard& board) {
    stringstream ss;
    ss << "----------------------" << endl;
    for (int i = 0; i < board.size(); i++) {
        ss << "|";
        for (int j = 0; j < board[i].size(); j++) {
            ss << setw(2) << board[i][j];
            if (j % 3 == 2) ss << "|";
        }
        ss << endl;
        if (i % 3 == 2) ss << "----------------------" << endl;

    }
    return ss.str();
}

string to_string(vector<pair<int, int>> v) {
    stringstream ss;
    ss << "{";
    for (auto& i : v) {
        ss << "(" << i.first << "," << i.second << ")";
        ss << " ";
    }
    ss << "}";
    return ss.str();
}

void print(vector<vector<int>> v) {
    for (auto& i : v) {
        for (auto& j : i) cout << j << " ";
        cout << endl;
    }
    cout << endl;
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print(vector<int> v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

template <typename T>
void print(string message, vector<T> v) {
    cout << message << " = ";
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

template <class K, class V>
void print(string message, unordered_map<K, V> map) {
    cout << message << ":" << endl;
    for (auto i : map) {
        cout << i.first << ":" << i.second << endl;
    }
    cout << endl;
}
string to_string(vector<double> arr) {
    stringstream ss;
    ss << "{";
    for (auto d : arr) {
        ss << d << " ";
    }
    ss << "}";
    return ss.str();
}

string to_string(pair<int, int> p) {
    return "(" + std::to_string(p.first) + "," + std::to_string(p.second) + ")";
}

template <class T>
class BinaryTreeNode {
public:
    T val;
    BinaryTreeNode* left, * right;
    BinaryTreeNode(T val) :val(val), left(nullptr), right(nullptr) {}
    string to_string() {
        return std::to_string(val);
    }
};
using ITNode = BinaryTreeNode<int>;

template <typename T>
string to_string(BinaryTreeNode<T>* root) {
    if (!root) return "";
    stringstream ss;
    queue<pair<BinaryTreeNode<T>*, int>> q;
    int offset = 20;
    q.push({ root, offset });

    while (!q.empty()) {
        int sz = q.size();
        stringstream cur;
        stringstream next;
        int prev = 0;
        int nextprev = 0;
        while (sz--) {
            auto item = q.front(); q.pop();
            cur << setw(item.second - prev) << item.first->val;
            if (item.first->left) {
                next << setw(item.second - nextprev - 2) << "/";
                nextprev = item.second - nextprev - 2;
                q.push({ item.first->left,item.second - 4 });
            }
            if (item.first->right) {
                next << setw(item.second - nextprev + 2) << "\\";
                nextprev = item.second - nextprev + 2;
                q.push({ item.first->right,item.second + 4 });
            }
            prev = item.second;
        }
        cur << endl;
        next << endl;
        ss << cur.str();
        ss << next.str();
    }

    return ss.str();
}

template <class T>
class LinkedListNode {
public:
    T val;
    LinkedListNode* prev;
    LinkedListNode* next;
    LinkedListNode(T val) :val(val), prev(nullptr), next(nullptr) {}
    string to_string() {
        return std::to_string(val);
    }
};

template <class T>
LinkedListNode<T>* Create(vector<T> v) {
    LinkedListNode<T>* cur = nullptr, * tmp = nullptr;
    for (auto i : v) {
        if (!cur) cur = tmp = new LinkedListNode<T>(i);
        else {
            tmp->next = new LinkedListNode<T>(i);
            tmp = tmp->next;
        }
    }
    return cur;
}

template <typename T>
int length(LinkedListNode<T>* node) {
    int len = 0;
    while (node) {
        len++;
        node = node->next;
    }

    return len;
}

template <typename T>
string to_string(LinkedListNode<T>* node) {
    stringstream ss;
    bool hasElem = false;
    ss << "{";
    while (node) {
        ss << node->to_string() << ", ";
        node = node->next;
        hasElem = true;
    }
    if (hasElem) ss.seekp(-2, std::ios_base::end);
    ss << "}";
    return ss.str();
}

template <typename T>
LinkedListNode<T>* Construct(vector<T> arr) {
    LinkedListNode<T>* head = nullptr;
    LinkedListNode<T>* l = head;
    for (auto i : arr) {
        if (!head) head = l = new LinkedListNode<T>(i);
        else {
            l->next = new LinkedListNode<T>(i);
            l = l->next;
        }
    }
    return head;
}

class Position {
public:
    int x, y;
    Position() : x(INT_MIN), y(INT_MIN) {}
    Position(int x, int y) : x(x), y(y) {}
    bool operator ==(Position& other) {
        return this->x == other.x && this->y == other.y;
    }
    string to_string() {
        stringstream ss;
        ss << "{";
        ss << std::to_string(x) << ",";
        ss << std::to_string(y);
        ss << "}";
        return ss.str();
    }
};

string to_bin(int num) {
    string str;
    while (num) {
        if (num & 1) str += "1";
        else str += "0";
        num >>= 1;
    }
    str.append(8 - str.length(), '0');
    std::reverse(str.begin(), str.end());
    return str;
}

template <typename T>
string to_string(pair<T, T> p) {
    return "{" + std::to_string(p.first) + ", " + std::to_string(p.second) + "}";
}

int sum(vector<int> a) {
    auto res = 0;
    for (auto i : a) res += i;
    return res;
}

int max(vector<int> a) {
    if (a.empty()) throw exception("empty");
    int mx = a[0];
    for (int i = 1; i < a.size(); i++) mx = max(mx, a[i]);
    return mx;
}

template <typename U, typename V>
string to_string(unordered_map<U, V>& map) {
    stringstream ss;
    ss << "{";
    for (auto e : map) {
        ss << e.first << "=" << e.second << ", ";
    }
    ss << "}";

    return ss.str();
}

//template <class T>
//class Set {
//    struct Compare {
//        bool operator()(const T& first, const T& second) {
//
//        }
//    };
//    unordered_set<T, decltype(comparator)> s;
//public:
//    Set() {}
//    Set(vector<T> v) {
//        for (auto i : v) add(i);
//    }
//    Set(std::function<bool(const T& f, const T& s)> comparator) :comparator(comparator) {}
//    bool add(T& item) {
//        if (contains(item)) return false;
//        s.insert(item);
//        return true;
//    }
//    bool contains(T& item) {
//        return s.find(item) != s.end();
//    }
//    bool remove(T& item) {
//        if(!contains(item)) return false;
//        s.erase(item);
//        return true;
//    }
//};

string to_string(bool res) {
    return res ? "True" : "False";
}