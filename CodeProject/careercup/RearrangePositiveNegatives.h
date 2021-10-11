#pragma once
#include "../Header.h"

class RearrangePositiveNegatives {
public:
    static void test() {
        vector<int> arr = { -1,6,9,-4,-10,-9,8,8,4 };
        rearrange(arr);

        cout << to_string(arr) << endl;
    }

    static void rearrange(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            if (i & 1 && arr[i] > 0) {
                int nextPos = findNextNeg(arr, i + 1);
                if (nextPos == -1) return;
                rotate(arr, i, nextPos);
            }
            else if (!(i & 1) && arr[i] < 0) {
                int nextNeg = findNextPos(arr, i + 1);
                if (nextNeg == -1) return;
                rotate(arr, i, nextNeg);
            }
        }
    }

    static int findNextPos(vector<int>& arr, int s) {
        while (s < arr.size() && arr[s] < 0) s++;
        if (s >= arr.size()) return -1;
        return s;
    }

    static int findNextNeg(vector<int>& arr, int s) {
        while (s < arr.size() && arr[s] > 0) s++;
        if (s >= arr.size()) return -1;
        return s;
    }

    static void rotate(vector<int>& arr, int l, int r) {
        int rotations = r - l;
        while (rotations-- > 0) rotateInternal(arr, l, r);
        while (rotations-- > 0) rotateInternal(arr, l, r);
    }

    static void rotateInternal(vector<int>& arr, int l, int r) {
        int tmp = arr[l];
        while (l < r) {
            arr[l] = arr[l + 1];
            l++;
        }
        arr[r] = tmp;
    }
};