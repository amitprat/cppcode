#pragma once
#include "../Header.h"

// https://www.careercup.com/question?id=5127611667709952
/*
Write code to give the character sequence given a word, For example, if the word is "CON", the function will print this:
Right//now we're at B
Right//now we're at C
OK//to select C
Down
DOwn
Right
Right
OK//to select O
Left//now at N
OK//to select N
*/
class  PathToPrintWordInSetupBox
{
public:
    static void test() {
        int colSize = 5;
        int limit = 25;
        string word = "constable";
        string path = getPath2(colSize, limit, word);

        cout << path << endl;
    }

    static string getPath(int colSize, int limit, string word) {
        string res;
        Point cur = { 0,0 };
        for (auto ch : word) {
            string curRes;
            Point des = { (ch - 'a') % 5,(ch - 'a') / 5 };
            //char curCh = 'a' + cur.y * colSize + cur.x;
            //cout << curCh << " -> " << ch << ": ";
            if (des.y > cur.y) {
                curRes += string(des.y - cur.y, 'd');
                cur.y = des.y;
            }

            if (des.y < cur.y) {
                curRes += string(cur.y - des.y, 'u');
                cur.y = des.y;
            }

            if (des.x > cur.x) {
                curRes += string(des.x - cur.x, 'r');
                cur.x = des.x;
            }

            if (des.x < cur.x) {
                curRes += string(cur.x - des.x, 'l');
                cur.x = des.x;
            }

            curRes += '\n';

            res += curRes;
            //cout << curRes;
        }

        return res;
    }

    static string getPath2(int colSize, int limit, string word) {
        string res;
        Point cur = { 0,0 };
        for (auto ch : word) {
            Point des = { (ch - 'a') % 5,(ch - 'a') / 5 };
            res += string(abs(des.y - cur.y), des.y > cur.y ? 'd' : 'u');
            res += string(abs(des.x - cur.x), des.x > cur.x ? 'r' : 'l');
            res += '\n';

            cur = des;
        }

        return res;
    }
};