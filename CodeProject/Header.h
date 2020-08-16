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
using namespace std;

using CBoard = vector<vector<char>>;
using IBoard = vector<vector<int>>;

class Interval {
public:
    int start;
    int end;
    Interval(int start, int end) : start(start), end(end) {}
    Interval() {}
    string to_string() {
        return "{" + std::to_string(start) + "," + std::to_string(end) + "}";
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