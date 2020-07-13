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
using namespace std;

class Node
{
public:
    int val;
    Node* next = nullptr;
    Node(int val, Node* next = nullptr) : val(val), next(next) {}
};

class PartitionList
{
public:
    static void test()
    {
        PartitionList obj;
        {
            Node* node = new Node(6);
            node->next = new Node(2);
            node->next->next = new Node(7);
            node->next->next->next = new Node(1);

            obj.print(node);
            int val = 3;
            obj.partition(node, val);
            obj.print(node);
        }
        {
            Node* node1 = new Node(6);
            node1->next = new Node(2);
            node1->next->next = new Node(7);
            node1->next->next->next = new Node(1);

            Node* node2 = new Node(9);
            node2->next = new Node(2);
            node2->next->next = new Node(9);
            node2->next->next->next = new Node(9);

            obj.print(node1);
            obj.print(node2);

            Node* sum = obj.add(node1, node2);

            obj.print(sum);
        }
    }

    void print(Node* node) {
        while (node) {
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
    }

    Node* add(Node* node1, Node* node2, int& carry)
    {
        if (node1 == nullptr || node2 == nullptr) return nullptr;
        Node* next = add(node1->next, node2->next, carry);
        int curSum = carry + node1->val + node2->val;
        carry = curSum / 10;
        Node* cur = new Node(curSum % 10);
        cur->next = next;
        return cur;
    }

    Node* add(Node* node1, Node* node2)
    {
        int carry = 0;
        Node* cur = add(node1, node2, carry);
        if (carry) {
            Node* newNode = new Node(carry);
            newNode->next = cur;
            return newNode;
        }

        return cur;
    }

    void partition(Node*& node, int val)
    {
        Node* runner = node;
        Node* cur = new Node(-1);
        Node* t = cur;
        cur->next = node;
        Node* runnerPrev = nullptr;

        while (runner) {
            Node* runnerNext = runner->next;
            if (runner->val < val) {
                Node* next = cur->next;
                if (runner != cur->next) {
                    cur->next = runner;
                    runner->next = next;
                    runnerPrev->next = runnerNext;
                }
                cur = runner;
            }
            runnerPrev = runner;
            runner = runnerNext;
        }
        node = t->next;
    }

    void partitionCareerCup(Node*& node, int val)
    {
        Node* head = node;
        Node* tail = node;

        while (node) {
            Node* next = node->next;
            if (node->val < val) {
                node->next = head;
                head = node;
            }
            else {
                tail->next = node;
                tail = node;
            }
            node = next;
        }
        tail->next = nullptr;
        node = head;
    }
};