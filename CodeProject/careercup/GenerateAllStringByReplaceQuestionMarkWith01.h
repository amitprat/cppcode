#pragma once
#include "../Header.h"

// https://www.careercup.com/question?id=5192571630387200
class GenerateAllStringByReplaceQuestionMarkWith01
{
public:
    static void test()
    {
        string str = "a?bc?def?g";
        vector<string> result = generateUsingBitSet(str);

        cout << to_string(result) << endl;
    }

    static vector<string> generateUsingBitSet(string str)
    {
        vector<string> result;
        int qMarks = 0;
        for (auto ch : str) {
            if (ch == '?') qMarks++;
        }
        int limit = pow(2, qMarks);
        for (int i = 0; i < limit; i++) {
            string cur;
            int cnt = qMarks - 1;
            for (auto ch : str) {
                if (ch == '?') {
                    if (i & (1 << cnt)) cur += '1';
                    else cur += '0';
                }
                else {
                    cur += ch;
                }
            }
            result.push_back(cur);
        }

        return result;
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