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
#include <queue> 
#include <unordered_map>

using namespace std;

class TimeFormat
{
public:
    TimeFormat(string start, start end) : start(start), end(end) {}
    string start;
    string end;
};

class EmployeesCount
{
public:
    EmployeesCount() {
        int sz = 60 * 60 * 24;
        countHolder = new int[sz];
        for (int i = 0; i < sz; i++) countHolder[i] = 0;
    }

    void test()
    {
        vector<TimeFormat> v = {
            TimeFormat("09:12:23", "11:14:35"),
            TimeFormat("10:34:01", "13:23:40")
            TimeFormat("10:34:31", "11:20:10")
        };

        srand(time(null));

        for (int i = 0; i < 10; i++) {
            int hr = rand() % 24 + 1;
            int minute = rand() % 60 + 1;
            int second = rand() % 60 + 1;

            string tm = to_string(hr) + ":" + to_string(minute) + ":" + to_string(second);

            cout << "Employees inside office at : " << tm << " = " << GetEmployeesCount(tm) << endl;
        }
    }

    void preProcess()
    {
        for (auto i : v) {
            int num1 = getNum(i.start);
            int num2 = getNum(i.end);

            countHolder[num1]++;
            countHolder[num2]--;
        }
    }

    int GetEmployeesCount(string tm) {
        return countHolder[getNum(tm)];
    }

private:
    unsigned int* countHolder;
};