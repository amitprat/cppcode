#pragma once

#include <time.h>
#include <stdlib.h>
#include <thread>
#include <vector>
#include <iostream>
#include <atomic> 
#include <mutex>
#include <time.h>
#include <fstream>
#include <tuple>
#include <sstream> 
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node* random = nullptr;

    Node(int val, Node* next = nullptr) : val(val), next(next) {}
};

class RandomLinkedList
{
public:
    static void test()
    {
        RandomLinkedList obj;
        Node* root = new Node(1);
        root->next = new Node(2);
        root->next->next = new Node(3);
        root->next->next->next = new Node(4);
        root->next->next->next->next = new Node(5);

        root->random = root->next->next->next;
        root->next->random = root;
        root->next->next->random = root->next;
        root->next->next->next->random = root->next->next->next->next;
        root->next->next->next->next->random = root->next->next;

        string res = obj.str(root);
        cout << "List: " << res << endl;

        Node* copy = obj.copyList(root);
        res = obj.str(copy);
        cout << "Copy: " << res << endl;
    }

    string str(Node* root)
    {
        stringstream ss;
        Node* tmp = root;
        while (tmp) {
            ss << "{" << tmp->val << "," << tmp->random->val << "}, ";
            tmp = tmp->next;
        }
        ss.seekg(-2);

        return ss.str();
    }

    Node* copyList(Node* root)
    {
        unordered_map<Node*, Node*> map;
        Node* tmp = root;
        Node* newtmp = new Node(root->val);
        Node* newRoot = newtmp;
        map[tmp] = newtmp;

        while (tmp->next) {
            newtmp->next = new Node(tmp->next->val);
            map[tmp->next] = newtmp->next;

            tmp = tmp->next;
            newtmp = newtmp->next;
        }

        tmp = root;
        newtmp = newRoot;

        while (tmp) {
            newtmp->random = map[tmp->random];
            tmp = tmp->next;
            newtmp = newtmp->next;
        }

        return newRoot;
    }
};