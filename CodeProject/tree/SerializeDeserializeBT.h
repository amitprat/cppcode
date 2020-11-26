#pragma once
#include <stdlib.h>
#include <thread>
#include <vector>
#include <iostream>
#include <atomic>
#include <mutex>
#include <time.h>
#include <fstream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <bitset>
#include <string>
#include <functional>
#include <future>
using namespace std;

class BT
{
public:
    class Node
    {
    public:
        int val;
        Node* left, * right;
        Node(int val, Node* left = nullptr, Node* right = nullptr) : val(val), left(left), right(right) {}
    };

    static void test()
    {
        BT obj;
        Node* node = new Node(23);
        node->left = new Node(1);
        node->right = new Node(51);
        node->left->right = new Node(20);
        node->right->left = new Node(2);

        cout << "Original: ";
        obj.print(node);
        cout << endl;

        string serialized = obj.serialize(node);
        cout << "Serialized :" << serialized << endl;

        Node* deserialized = obj.deserialize(serialized);
        cout << "De serialized:";
        obj.print(node);
    }

    void print(Node* node) {
        if (node) {
            print(node->left);
            cout << node->val << " ";
            print(node->right);
        }
    }

    string serialize(Node* node)
    {
        if (node) {
            string result;
            result += ::to_string(node->val);
            string left = serialize(node->left);
            if (!left.empty()) result += " " + left;

            string right = serialize(node->right);
            if (!right.empty()) result += " " + right;

            return result;
        }

        return "#";
    }

    Node* deserialize(string serilized)
    {
        vector<int> items = split(serilized);
        return deserialize(items, 0, INT_MIN);
    }

    Node* deserialize(vector<int> items, int index, int marker)
    {
        if (index >= items.size()) return nullptr;
        if (items[index] == marker) return nullptr;
        Node* root = new Node(items[index]);
        root->left = deserialize(items, index + 1, marker);
        root->right = deserialize(items, index + 1, marker);

        return root;
    }

    vector<int> split(string serialized)
    {
        vector<int> result;
        for (char ch : serialized) {
            if (ch == ' ') continue;
            if (ch == '#') result.push_back(INT_MIN);
            else result.push_back(ch - '0');
        }
        return result;
    }
};