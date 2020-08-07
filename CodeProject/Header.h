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
#include <unordered_map>
#include <unordered_set>
#include <cassert>
using namespace std;

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