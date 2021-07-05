#include "../Header.h"

class FindNumberOccursOnlyOnce {
public:
    static void test() {
        FindNumberOccursOnlyOnce obj;
        vector<int> arr = { 2, 1,9,4, 5, 1, 4, 2, 2, 4, 1,5,5 };
        cout << obj.findNum(arr) << endl;

        cout << obj.findNum2(arr) << endl;
    }

    int findNum(vector<int> arr) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int cur = 0;
            for (auto num : arr) {
                if (num & (1 << i)) {
                    cur = (cur + 1) % 3;
                }
            }
            res |= cur << i;
        }

        return res;
    }

    int findNum2(vector<int> arr) {
        int    ones = 0;
        int    twos = 0;
        int not_threes;
        int x;

        for (int i = 0; i < arr.size(); i++)
        {
            x = arr[i];
            twos |= ones & x;
            ones ^= x;
            not_threes = ~(ones & twos);
            ones &= not_threes;
            twos &= not_threes;
        }

        return ones;
    }
};