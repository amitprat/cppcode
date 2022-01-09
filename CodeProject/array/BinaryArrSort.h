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

			vector<int> arr1 = arr, arr2 = arr;
			obj.sort1(arr1);
			obj.sort1(arr2);

			assert(isEqual(arr1, arr2));

			cout << "---Rearranged array is--- \n";
			cout << to_string(arr1) << endl;

			cout << "\n======================\n";
		}
	}

	void sort1(vector<int>& arr) {
		int s = 0, e = arr.size() - 1;
		while (s < e) {
			if (arr[s] == 0) s++;
			else {
				if (arr[e] == 0) swap(arr[s++], arr[e]);
				else e--;
			}
		}
	}

	void sort2(vector<int>& arr) {
		for (int i = 0, j = 0; j < arr.size(); j++) {
			if (arr[j] == 0) swap(arr[i++], arr[j]);
		}
	}
};