#pragma once
#include "../Header.h"

/*
Given an array having 16000 unique integers, each lying within the range 1<x<20000, how do u sort it. U can load only 1000 numbers at a time in memory.
*/

/*
use bit vector to store each integer in single bit. 625 integers are required to store 20000 numbers

int arr[625] = {0};

ex: to store data 2000
arr index = 2000/32 = 62
bit position = 2000%32 = 16

now make bit position 16 of array index 62 arr[62] to 1

using this bit vectors we can store data range from 1 - 20000 in 625 integers..

after storing all data in bit vectors, check all bit positions of arr[0], arr[1]..... arr[625]... if any bit position is set to 1 then store back that data into array

lets arr[10] bit position 15 is set to 1 then this is equivalent to data 10*32+15 = 335
*/

class Bitset {
    int sz = 0;
    int* arr = nullptr;
    int numSz = 0;
public:
    Bitset(int range) {
        this->numSz = (8 * sizeof(int));
        this->sz = range / numSz;
        arr = new int[this->sz];
        memset(arr, 0, sizeof(int) * this->sz);
    }
    void add(int number) {
        int pos = number / numSz;
        int off = number % numSz;

        set(pos, off);
    }

    void set(int pos, int off) {
        arr[pos] |= (1 << off);
    }
    bool isset(int number) {
        int pos = number / numSz;
        int off = number % numSz;

        return isset(pos, off);
    }

    bool isset(int pos, int off) {
        return arr[pos] & (1 << off);
    }
};

class SortNumbers {
public:
    static void test() {
        SortNumbers obj;
        vector<int> a;
        srand(time(nullptr));
        for (int i = 0; i < 20; i++) {
            a.push_back(rand() % 20000 + 1);
        }
        int range = 20000;
        print("Original Array", a);
        obj.sort(a, range);
        print("Sorted Array", a);
    }

    void sort(vector<int>& a, int range) {
        Bitset bitset(range);
        for (auto e : a) {
            bitset.add(e);
        }
        a.clear();
        for (int i = 0; i < range; i++) {
            if (bitset.isset(i)) a.push_back(i);
        }
    }
};