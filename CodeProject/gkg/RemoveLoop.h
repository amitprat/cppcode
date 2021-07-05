#pragma once
#include "../Header.h"

class RemoveLoop {
public:
    static void test() {
        RemoveLoop obj;
        LinkedListNode<int>* head = new LinkedListNode<int>(1);
        head->next = new LinkedListNode<int>(2);
        head->next->next = new LinkedListNode<int>(3);
        head->next->next->next = new LinkedListNode<int>(4);
        head->next->next->next->next = new LinkedListNode<int>(5);
        head->next->next->next->next->next = new LinkedListNode<int>(6);
        head->next->next->next->next->next->next = head->next->next;

        cout << "List : ";
        obj.print(head);

        auto newHead = obj.removeLoop(head);
        cout << "List : ";
        obj.print(newHead);
    }

    void print(LinkedListNode<int>* head) {
        unordered_set<int> s;
        while (head && (s.find(head->val) == s.end())) {
            cout << head->val << " ";
            s.insert(head->val);
            head = head->next;
        }
        if (head) cout << " ~ ";
        cout << endl;
    }

    LinkedListNode<int>* removeLoop(LinkedListNode<int>* node) {
        if (!node || !node->next) return node;
        auto slow = node;
        auto fast = node->next;

        while (slow != fast && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (!slow || !fast) {
            cout << "No loop" << endl;
            return node;
        }
        cout << "Loop found at node " << slow->val << endl;

        LinkedListNode<int>* prev = nullptr;
        slow = slow->next;
        auto tmp = node;
        while (tmp && slow && (tmp != slow)) {
            tmp = tmp->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = nullptr;

        return node;
    }
};