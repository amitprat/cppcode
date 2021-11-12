#pragma once
#include "../Header.h"

/*
https://www.careercup.com/question?id=6276805505843200

Find if the given expression contains redundant parantheses. ex :if expr = a+(b*c) , print false, if expr = a+((b*c)), print true.
*/
class IdentifyRedundanctParenthesis
{
public:
    static void test() {
        vector<string> strs = { "a+(b*c)","a+((b*c))" };

        for (auto str : strs) {
            if (isValid(str)) {
                cout << str << " is valid" << endl;
            }
            else {
                cout << str << " is not valid" << endl;
            }
        }
    }

    static bool isValid(string str) {
        stack<char> st;

        for (auto ch : str) {
            if (ch == '(') st.push(ch);
            else if (ch == ')') {
                if (st.empty() || st.top() == '(') return false;
                st.pop();
                if (st.empty() || st.top() != '(') return false;
                st.pop();
            }
            else {
                if (st.empty() || st.top() == '(') st.push(ch);
            }
        }

        return true;
    }
};