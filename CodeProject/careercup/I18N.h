#pragma once
#include "../Header.h"

//https://www.careercup.com/question?id=5733696185303040
class I18N
{
public:
    static void test() {
        string str = "careercup";

        print(str);
    }

    static void print(string str) {
        int n = str.length();
        for (int i = n - 2; i >= 1; i--) {
            int rem = n - i;
            for (int k = 1; k < rem; k++)
            {
                string first = str.substr(0, k);
                string middle = to_string(i);
                string second = str.substr(n - rem + k, rem - k);
                cout << first << middle << second << endl;
            }
        }
    }
};