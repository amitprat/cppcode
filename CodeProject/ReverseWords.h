#pragma once
#include <time.h>
#include <stdlib.h>
#include <thread>
#include <vector>
#include <iostream>
#include <atomic>
#include <mutex>
using namespace std;

class ReverseWords
{
public:
    void reverse(string& str, int s, int e) {
        while (s < e) {
            swap(str[s++], str[e--]);
        }
    }

    void reverse(string& str)
    {
        int l = str.length();
        int s = 0;
        reverse(str, s, l - 1);

        for (int i = 0; i < l; i++) {
            if (str[i] == ' ') {
                reverse(str, s, i - 1); s = i + 1;
            }
        }
        if (s != 0) reverse(str, s, l - 1);
    }

    void test()
    {
        string str = "This is test string";

        cout << "Original String:- " << str << endl;;
        reverse(str);
        cout << "Reversed String:- " << str << endl;

        str = "This is one more example to test approach";

        cout << "Original String:- " << str << endl;;
        reverse(str);
        cout << "Reversed String:- " << str;
    }
};