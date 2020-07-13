#pragma once

#include <time.h>
#include <stdlib.h>
#include <thread>
#include <vector>
#include <iostream>
#include <atomic>
#include <algorithm>
#include <time.h>
#include <fstream>
#include <tuple>
#include <queue>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

class ArrangePositiveNegativeNumbers
{
public:
    static void test(vector<int> v)
    {
        ArrangePositiveNegativeNumbers obj;
        cout << "Input: ";
        for (auto i : v) cout << i << " ";
        cout << "Output: ";
        obj.arrangeNumbers(v);
        for (auto i : v) cout << i << " ";
        cout << endl;
    }

    void arrangeNumbers(vector<int>& v)
    {
        normalSort(v);
        //mergeSort(v, 0, v.size() - 1);
    }

private:
    void normalSort(vector<int>& v)
    {
        int pos = 0;
        int cur = 0;
        for (; cur < v.size(); cur++) {
            if (v[cur] < 0) rightShift(v, pos, cur);
        }
    }

    void rightShift(vector<int>& v, int pos, int cur)
    {
        while (v[pos] < 0 && pos < v.size()) pos++;
        int tmp = v[cur];
        for (int i = cur - 1; i >= pos; i--) v[i + 1] = v[i];
        v[pos] = tmp;
    }

    void mergeSort(vector<int>& v, int l, int r)
    {
        if (l < r)
        {
            int m = (l + r) / 2;
            mergeSort(v, l, m);
            mergeSort(v, m + 1, r);
            merge(v, l, m, r);
        }
    }

    void merge(vector<int>& v, int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;
        int* tmp1 = new int[n1];
        int* tmp2 = new int[n2];
        for (int i = l, j = 0; i <= m; i++, j++) tmp1[j] = v[i];
        for (int i = m + 1, j = 0; i <= r; i++, j++) tmp2[j] = v[i];
        int k = l;
        int i = 0, j = 0;
        for (; i < n1 && j < n2;) {
            if (tmp1[i] < 0) v[k++] = tmp1[i++];
            else if (tmp2[j] < 0)  v[k++] = tmp2[j++];
            else break;
        }

        for (; i < n1; i++, k++) {
            v[k] = tmp1[i];
        }

        for (; j < n2; j++, k++) {
            v[k] = tmp2[j];
        }
    }
};