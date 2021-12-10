#pragma once
#include "../Header.h"

class FindMissingNumber {
public:
	static void test() {
		int num = findMissingNumber("9799100101102");
		cout << num << endl;
	}

	static int findMissingNumber(string str) {
		int n = str.size();
		for (int i = 1; i <= n && i <= 7; i++) {
			int num = stoi(str.substr(0, i));

			int missingNum = -1;

			int j = i;
			for (; j + 1 + log10(num) <= n; j += 1 + log10(num)) {
				int nextNum = stoi(str.substr(j, 1 + log10(num + 1)));

				if (nextNum == num) {
					num = nextNum;
				}
				else if (nextNum == num + 2 && missingNum == -1) {
					missingNum = num + 1;
					num = nextNum;
				}
				else {
					break;
				}
			}

			if (j == n) return missingNum == -1 ? (num + 1) : missingNum;
		}

		return -1;
	}
};