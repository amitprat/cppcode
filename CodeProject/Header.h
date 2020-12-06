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

string to_string(vector<double> arr) {
    stringstream ss;
    ss << "{";
    for (auto d : arr) {
        ss << d << " ";
    }
    ss << "}";
    return ss.str();
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