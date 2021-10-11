#pragma once
#include "../Header.h"

class LexographicalSmallestString
{
public:
    static void test()
    {
        string str = "cbacdcbc";
        auto res = smallest(str);
        cout << "Smallest- " << res << endl;
    }

    static string smallest(string str)
    {
        int n = str.length();
        vector<int> lastIndex(26, -1); // <character to last index of it in string> mapping
        vector<int> next(n);
        for (int i = n - 1; i >= 0; i--) {
            int cur = str[i] - 'a';
            next[i] = lastIndex[cur]; // last index for this character at this position
            lastIndex[cur] = i;
        }

        string res;
        vector<bool> visited(26, false);
        for (int i = 0; i < n; i++) {
            int cur = str[i] - 'a';
            if (visited[cur]) continue; // if this character already included in result, exclude it

            if (next[cur] == -1) { // if this is last index for this character, include it and mark it as visited.
                res += str[i];
                visited[cur] = true;
            }
            else { // otherwise, look for next smallest character right to it until end or this character is only character. Include the smallest character.
                char smallest = str[i];
                int j = i + 1;
                while (j < n) {
                    if (visited[cur]) continue;

                    if (str[j] < smallest) smallest = str[j];
                    if (next[j] == -1) break; // this is last index for this character so break here, we must include this
                    j++;
                }
                if (str[i] <= smallest) {
                    res += str[i];
                    visited[cur] = true;
                }
            }
        }
    }
};