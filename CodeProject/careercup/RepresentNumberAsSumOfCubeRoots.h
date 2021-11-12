#pragma once
#include "../Header.h"

// https://www.careercup.com/question?id=5647694703886336
/*
Write a function that would print all positive numbers smaller than n that can be expressed as the sum of two cubes in two different ways. Bonus: calculate the complexity of that function.

For example, 1729 is one such number because 1729 = 1^3 + 12^3 = 9^3 + 10^3.
*/
class RepresentNumberAsSumOfCubeRoots
{
public:
    static void test()
    {
        RepresentNumberAsSumOfCubeRoots obj;
        int num = 1729;
        obj.calculateCubeRootSum(num);
    }
private:
    void calculateCubeSum(int n) {
        int cuberoot = cbrt(n);
        int* a = new int[cuberoot];

        // construct array
        for (int i = 0; i < cuberoot; i++) {
            a[i] = (i + 1) * (i + 1) * (i + 1);
        }

        int fwd = 0;
        int bck = cuberoot - 1;
        while (fwd < bck) {

            if (a[fwd] + a[bck] < n)
                fwd++;
            else if (a[fwd] + a[bck] > n)
                bck--;
            else {
                cout << cbrt(a[fwd]) << ", " << cbrt(a[bck]) << endl;
                fwd++;
                bck--;
            }
        }
    }

    void calculateCubeRootSum(int n)
    {
        int m = cbrt(n);
        vector<int> cubeRoots;
        for (int i = 0; i <= m; i++) cubeRoots.push_back(pow(i, 3));

        vector<string> result;
        calculateCubeRootSum(cubeRoots, m, n, result);
    }

    void calculateCubeRootSum(vector<int> cubeRoots, int index, int total, vector<string> result)
    {
        if (total == 0) {
            cout << to_string(result) << endl;
            return;
        }
        if (total < 0 || index < 0) return;

        calculateCubeRootSum(cubeRoots, index - 1, total, result);
        result.push_back(to_string((int)cbrt(cubeRoots[index])) + "^3");
        calculateCubeRootSum(cubeRoots, index - 1, total - cubeRoots[index], result);
        result.pop_back();
    }
};
