#pragma once
#include "../header.h"

class PrintA1B1A2B2 {
    mutex m;
    condition_variable cv1, cv2, cv3, cv4;
    int val = 1;
    volatile int limit = 30;
public:
    static void test() {
        PrintA1B1A2B2 obj;
        obj.print();
    }

    void print() {
        thread t1([this]() {
            printA1();
            printA2();
            });

        thread t2([this]() {
            printB1();
            printB2();
            });

        t1.join();
        t2.join();
    }
    void printA1() {
        unique_lock lock(m);
        cv1.wait(lock, [this]() {return val == 1; });
        cout << "A1" << endl;
        val++;
        limit--;
        lock.unlock();
        cv2.notify_one();
    }
    void printA2() {
        unique_lock lock(m);
        cv3.wait(lock, [this]() { return val == 3; });
        cout << "A2" << endl;
        val++;
        limit--;
        lock.unlock();
        cv4.notify_one();
    }
    void printB1() {
        unique_lock lock(m);
        cv2.wait(lock, [this]() { return val == 2; });
        cout << "B1" << endl;
        val++;
        limit--;
        lock.unlock();
        cv3.notify_one();
    }
    void printB2() {
        unique_lock lock(m);
        cv4.wait(lock, [this]() { return val == 4; });
        cout << "B2" << endl;
        val = 1;
        limit--;
        lock.unlock();
        cv1.notify_one();
    }
};

class PrintA1B1A2B2InLoop {
private:
    mutex m;
    condition_variable cv1, cv2, cv3, cv4;
    atomic<int> limit = 20;
    int val = 0;

public:
    static void test() {
        PrintA1B1A2B2InLoop obj;
        obj.print();
    }

    void print() {
        thread t1([this]() {printA1A2(); });
        thread t2([this]() {printB1B2(); });

        t1.join();
        t2.join();
    }

    void printA1A2() {
        while (limit > 0) {
            printStr("A1", 0, cv1, cv2);
            printStr("A2", 2, cv3, cv4);
        }
    }

    void printB1B2() {
        while (limit > 0) {
            printStr("B1", 1, cv2, cv3);
            printStr("B2", 3, cv4, cv1);
        }
    }

    void printStr(string str, int expected, condition_variable& cv, condition_variable& next) {
        unique_lock lock(m);
        cv.wait(lock, [this, expected]() {return val == expected; });
        val = (val + 1) % 4;
        if (limit > 0) {
            cout << str;
            limit--;
        }
        lock.unlock();
        next.notify_one();
    }
};