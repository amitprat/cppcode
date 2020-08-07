/*
0
---Rearranged array is---
0

======================
---Given array is---
1
---Rearranged array is---
1

======================
---Given array is---
0 0
---Rearranged array is---
0 0

======================
---Given array is---
1 1
---Rearranged array is---
1 1

======================
---Given array is---
0 1
---Rearranged array is---
0 1

======================
---Given array is---
0 1 0
---Rearranged array is---
0 0 1

======================
---Given array is---
1 0 1
---Rearranged array is---
0 1 1

======================
---Given array is---
0 0 0 0 0 0 0 0 0 0
---Rearranged array is---
0 0 0 0 0 0 0 0 0 0

======================
---Given array is---
1 1 1 1 1 1 1 1 1 1
---Rearranged array is---
1 1 1 1 1 1 1 1 1 1

======================
---Given array is---
1 0 0 0 0 0 1 0 0 0
---Rearranged array is---
0 0 0 0 0 0 0 0 1 1

======================
---Given array is---
1 0 0 1 1 1 1 1 0 0
---Rearranged array is---
0 0 0 0 1 1 1 1 1 1

======================
*/
#pragma once
#include "../header.h"

class BinaryArrSort
{
public:
    static void test()
    {
        BinaryArrSort obj;
        vector<vector<int>> arrs = {
            {},
            {0},
            {1},
            {0,0},
            {1,1},
            {0,1},
            {0,1,0},
            {1,0,1},
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
            { 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
            { 1, 0, 0, 1, 1, 1, 1, 1, 0, 0 }
        };

        for (auto arr : arrs) {
            cout << "---Given array is--- \n";
            cout << to_string(arr) << endl;

            obj.sort1(arr);

            cout << "---Rearranged array is--- \n";
            cout << to_string(arr) << endl;

            cout << "\n======================\n";
        }
    }

    void sort1(vector<int>& a)
    {
        int s = 0, e = a.size() - 1;
        while (s < e) {
            if (a[s] == 0) s++;
            else {
                if (a[e] == 0) swap(a[s], a[e]);
                else e--;
            }
        }
    }

    void sort2(vector<int>& a)
    {
        int j = -1;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == 0) {
                j++;
                swap(a[i], a[j]);
            }
        }
    }
};