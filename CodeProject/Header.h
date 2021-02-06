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
using namespace std;

using CBoard = vector<vector<char>>;
using IBoard = vector<vector<int>>;

class Interval {
public:
    int start;
    int end;
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

template <class T>
class Point {
public:
    T x, y;
    Point(T x = default(T), T y = default(T)) :x(x), y(y) {}
    Point operator +(const Point& other) {
        Point result(x + other.x, y + other.y);
        return result;
    }
    string to_string() {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
};

string to_string(vector<Interval>& input) {
    stringstream ss;
    ss << "[";
    for (auto& i : input) ss << i.to_string() << ", ";
    ss << "]";
    return ss.str();
}

string to_string(vector<int>& input) {
    stringstream ss;
    ss << "[";
    for (auto& i : input) ss << i << ", ";
    ss << "]";
    return ss.str();
}

template <typename T>
string to_string(vector<T> input) {
    stringstream ss;
    ss << "[";
    for (auto& i : input) ss << i << ", ";
    ss << "]";
    return ss.str();
}

string to_string(vector<string>& input) {
    stringstream ss;
    ss << "[";
    for (auto& i : input) ss << i << ", ";
    ss << "]";
    return ss.str();
}

string to_string(CBoard& board) {
    stringstream ss;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            ss << setw(4) << board[i][j] << "\t";
        }
        ss << endl;
    }
    return ss.str();
}

string to_string(IBoard& board) {
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
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void print(vector<int> v) {
    for (auto i : v) {
        cout << i << " ";
    }
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