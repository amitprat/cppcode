#pragma once
#include "../Header.h"

class PrintEvenOddNumbersUsing2Threads {
    mutex m;
    condition_variable cv1, cv2;
    int pos = 0;

public:
    static void test() {
        PrintEvenOddNumbersUsing2Threads obj;

        int arr[] = { 3,1 ,2, 5, 6, 7, 8, 10, 9 };
        int n = sizeof(arr) / sizeof(int);

        obj.printNumbers(arr, n);
    }

    void printNumbers(int arr[], int n) {
        thread t1([arr, n, this]() {printEvenNumbers(arr, n); });
        thread t2([arr, n, this]() {printOddNumbers(arr, n); });

        t1.join();
        t2.join();
    }

    void printEvenNumbers(int arr[], int n) {
        while (true) {
            unique_lock lock(m);
            cv1.wait(lock, [this, arr, n]() {return pos >= n || !(arr[pos] & 1); });
            if (pos >= n) {
                lock.unlock();
                break;
            }

            cout << "Even thread: " << arr[pos] << endl;
            pos++;

            lock.unlock();
            if (arr[pos] & 1) cv2.notify_one();
        }
    }

    void printOddNumbers(int arr[], int n) {
        while (true) {
            unique_lock lock(m);
            cv2.wait(lock, [this, arr, n]() {return (pos >= n || arr[pos] & 1); });
            if (pos >= n) {
                lock.unlock();
                break;
            }

            cout << "Odd thread: " << arr[pos] << endl;
            pos++;

            lock.unlock();
            if (!(arr[pos] & 1)) cv1.notify_one();
        }
    }
};