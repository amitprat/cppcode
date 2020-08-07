#include <stdlib.h>
#include <thread>
#include <vector>
#include <iostream>
#include <atomic>
#include <mutex>
#include <time.h>
#include <fstream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <bitset>
#include <string>
#include <map>
using namespace std;

class GenerateMaxNumber
{
public:
    static void test()
    {
        GenerateMaxNumber obj;
        vector<pair<int, int>> inputs = {
            {132,1},
            {132,2},
            {7899,2},
            {8799,2}
        };
        for (auto input : inputs) {
            auto res = obj.genMax(input.first, input.second);
            cout << input.first << "," << input.second << " : " << res << endl;
        }
    }

    int genMax(int number, int K)
    {
        int mx = number;
        string str = to_string(number);
        int len = str.length();
        genMax(str, K, 0, len, mx);

        return mx;
    }

    void genMax(string number, int k, int idx, int len, int& mx)
    {
        if (idx == len || k == 0) { mx = max(mx, stoi(number)); return; }
        for (int i = idx; i < len; i++) {
            swap(number[i], number[idx]);
            genMax(number, k - 1, idx + 1, len, mx);
            swap(number[i], number[idx]);
        }
    }
};