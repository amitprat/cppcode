#pragma once
#include "../header.h"

namespace cq {
    template <class T>
    class CircularQueue {
    public:
        class Node {
        public:
            T val;
            Node* prev, * next;
            Node(T val) :val(val), prev(nullptr), next(nullptr) {}
        };
    private:
        Node* head, * tail;
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
                head = tail = new Node(item);
            }
            else {
                tail->next = new Node(item);
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

    template <class T>
    class ArrayCircularQueue {
    private:
        T* arr = nullptr;
        int cap = 0;
        int start, end;
    public:
        ArrayCircularQueue(int cap) :cap(cap) {
            arr = new T[cap];
            start = end = 0;
        }
        static void test() {
            ArrayCircularQueue<string> cq(10);
            auto pushd = [&cq](auto item) mutable {
                cout << "Push Item: " << item << endl;
                cq.push(item);
            };
            auto popd = [&cq]() mutable {
                cout << "Pop Item: " << cq.pop() << endl;
            };
            auto print = [&cq]() mutable {
                cout << "Queue State: ";
                while (!cq.empty()) cout << cq.pop() << " ";
                cout << endl;
            };

            try {
                pushd("1");
                pushd("2");
                pushd("3");
                pushd("4");
                pushd("5");
                pushd("6");
                popd();
                pushd("7");
                pushd("8");
                pushd("9");
                pushd("10");
                popd();
                pushd("11");
                popd();
                popd();
                pushd("12");
                pushd("13");
                popd();
                pushd("14");
                popd();
                popd();
                popd();
                pushd("15");
                pushd("16");
                print();
            }
            catch (exception& e) {
                cout << e.what() << endl;
            }
        }
        void push(T item) {
            if (isFull()) throw exception("Queue is full");
            arr[end] = item;
            end = index(end + 1);
        }
        T pop() {
            if (empty()) throw exception("Queue is empty");
            auto item = arr[start];
            start = index(start + 1);
            if (empty()) reset();

            return item;
        }
        T front() {
            if (empty()) throw exception("Queue is empty");
            return arr[start];
        }
        bool empty() {
            return start == end;
        }
        int size() {
            return (end + cap - start) % cap;
        }
        bool isFull() {
            return start == index(end + 1);
        }
        int index(int cur) {
            return cur % cap;
        }
        void reset() {
            start = end = 0;
        }
    };
}