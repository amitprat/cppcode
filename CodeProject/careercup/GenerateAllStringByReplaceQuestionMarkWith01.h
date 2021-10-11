#pragma once
#include "../Header.h"

class GenerateAllStringByReplaceQuestionMarkWith01
{
public:
    static void test()
    {
        string str = "a?bc?def?g";
        vector<string> result = generateRec(str);

        cout << to_string(result) << endl;
    }

    static vector<string> generateRec(string str)
    {
        vector<string> result;

        generateRec(str, 0, "", result);

        return result;
    }

    static void generateRec(string str, int index, string cur, vector<string>& result)
    {
        if (index == str.length()) {
            result.push_back(cur);
            return;
        }

        if (str[index] == '?')
        {
            generateRec(str, index + 1, cur + "0", result);
            generateRec(str, index + 1, cur + "1", result);
        }
        else {
            generateRec(str, index + 1, cur + str[index], result);
        }
    }

    static vector<string> generate(string str)
    {
        int index = 0;
        int n = str.length();
        queue<string> q;
        vector<string> result;
        do {
            if (index == n) {
                result.push_back(q.front());
                q.pop();
                continue;
            }

            string cur;
            bool hasMark = false;
            while (index < n) {
                index++;
                if (str[index - 1] == '?') { hasMark = true; break; }
                cur += str[index - 1];
            }
            int m = q.size();
            if (m == 0) {
                if (hasMark) {
                    q.push(cur + "0");
                    q.push(cur + "1");
                }
                else {
                    q.push(cur);
                }
            }
            else {
                while (m--) {
                    auto f = q.front(); q.pop();
                    if (hasMark) {
                        q.push(f + cur + "0");
                        q.push(f + cur + "1");
                    }
                    else {
                        q.push(f + cur);
                    }
                }
            }
        } while (!q.empty());

        return result;
    }
};