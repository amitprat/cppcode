#pragma once
#include "../header.h"

namespace cq {
    template <class T>
    class Node {
    public:
        T val;
        Node* prev, * next;
        Node(T val) :val(val), prev(nullptr), next(nullptr) {}
    };

    template <class T>
    class CircularQueue {
    private:
        Node<T>* head, * tail;
        int sz = 0;
    public:
        CircularQueue() :head(nullptr), tail(nullptr) {}
        static void test() {
            CircularQueue<string> dq;
            auto pushd = [&dq](auto item) mutable {
                cout << "Pushing item = " << item << endl;
                dq.push(item);
            };
            auto popd = [&dq]() mutable {
                cout << "Popped item = " << dq.pop() << endl;
            };
            auto frontd = [&dq]() mutable {
                cout << "Front item = " << dq.front() << endl;
            };
            auto print = [&dq]() mutable {
                cout << "Queue State: ";
                while (!dq.empty()) {
                    cout << dq.pop() << " ";
                }
                cout << endl;
            };

            try {
                pushd("1");
                pushd("2");
                popd();
                pushd("3");
                pushd("4");
                pushd("5");
                pushd("6");
                popd();
                pushd("7");
                pushd("8");
                pushd("9");
                pushd("10");
                popd(); popd();
                print();
            }
            catch (exception& e) {
                cout << e.what() << endl;
            }
        }
        void push(T item) {
            if (head == nullptr) {
                head = tail = new Node<T>(item);
            }
            else {
                tail->next = new Node<T>(item);
                tail = tail->next;
                tail->next = head;
            }
            sz++;
        }
        T pop() {
            if (head == nullptr) throw exception("Queue is empty");
            if (head == tail) {
                auto val = head->val;
                delete head;
                head = tail = nullptr;
                sz--;
                return val;
            }

            auto f = head;
            head = head->next;
            tail->next = head;
            auto val = f->val;
            delete f;
            sz--;

            return val;
        }
        T front() {
            if (head == nullptr) throw exception("Queue is empty");
            return head->val;
        }
        bool empty() {
            return head == nullptr;
        }
        int size() {
            return sz;
        }
    };
}