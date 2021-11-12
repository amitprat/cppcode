#pragma once
#include "../Header.h"

/*
https://www.careercup.com/question?id=13575664


Q1.- Written exam (Amazon, Bangalore)

Given a singly link list and a number 'K', swap the Kth node from the start with the Kth node from the last. Check all the edge cases.

Sample Input: 1->2->3->4->5->6->7->8 and K = 3
Sample Output : 1->2->6->4->5->3->7->8

Sample Input: 1->2->3->4->5->6->7->8 and K = 10
Sample Output: print error "LIST IS OF LESSER SIZE".
*/
class SwapKthNodesFromLinkedList
{
    struct Node {
        int val;
        Node* next = nullptr;
        Node() {}
        Node(int val) : val(val) {}
    };
public:
    static void test() {
        Node* root = new Node(1);
        root->next = new Node(2);
        root->next->next = new Node(3);
        root->next->next->next = new Node(4);
        root->next->next->next->next = new Node(5);
        root->next->next->next->next->next = new Node(6);
        root->next->next->next->next->next->next = new Node(7);
        root->next->next->next->next->next->next->next = new Node(8);
        root->next->next->next->next->next->next->next->next = new Node(9);
        print(root);

        int sz = length(root);

        Node* newNode = root;
        for (int i = 1; i <= sz + 1; i++) {
            newNode = swapNodes(newNode, i);
            print(newNode);
        }
    }

    static Node* swapNodes(Node* root, int k) {
        // Find prev1 and kth node from beginning
        Node* kthNodeFromStart = root;
        Node* prev1 = nullptr;
        for (int i = 1; i < k; i++) {
            prev1 = kthNodeFromStart;
            kthNodeFromStart = kthNodeFromStart->next;

            if (!kthNodeFromStart) {
                cout << "K is outside list range" << endl;
                return root;
            }
        }

        // Find prev2 and kth node from end
        Node* kthNodeFromEnd = root;
        Node* tmp = kthNodeFromStart->next;
        Node* prev2 = nullptr;
        while (tmp) {
            tmp = tmp->next;
            prev2 = kthNodeFromEnd;
            kthNodeFromEnd = kthNodeFromEnd->next;
        }

        // Swap links from prev nodes and correct root node
        if (prev1) {
            prev1->next = kthNodeFromEnd;
        }
        else {
            root = kthNodeFromEnd;
        }

        // Swap links from prev nodes and correct root node
        if (prev2) {
            prev2->next = kthNodeFromStart;
        }
        else {
            root = kthNodeFromStart;
        }

        // swap next nodes
        tmp = kthNodeFromStart->next;
        kthNodeFromStart->next = kthNodeFromEnd->next;
        kthNodeFromEnd->next = tmp;

        // return updated root
        return root;
    }

    static void print(Node* root) {
        cout << "List: ";
        while (root) {
            cout << root->val << " ";
            root = root->next;
        }
        cout << endl;
    }

    static int length(Node* root) {
        int len = 0;
        while (root) {
            len++;
            root = root->next;
        }

        return len;
    }
};