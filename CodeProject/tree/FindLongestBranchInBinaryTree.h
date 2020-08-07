#pragma once

#include <time.h>
#include <stdlib.h>
#include <thread>
#include <vector>
#include <iostream>
#include <atomic>
#include <unordered_set>
#include <time.h>
#include <fstream>
#include <tuple>
#include <queue>
#include <unordered_map>
#include <string>
#include <sstream>
#include <map>
using namespace std;

class FindLongestBranch
{
public:
    struct Node {
        int val;
        Node* left, * right;
        Node(int val) : val(val), left(nullptr), right(nullptr) {}
    };
    static void test() {
        Node* root;
    }
};