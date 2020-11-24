#pragma once
#include "../header.h"

/*
* one unsorted array is given.Find out the index i and j ,j> i for which a[j] - a[i] is maximum.perform in linear time complexity
* private void MaxDiff(int[] a)
       {
           int min = a[0]; // assume first element as minimum
           int maxdiff = 0;
           int posi = -1, posj = -1, minpos = 0;

           for (int i = 1; i < a.Length; i++)
           {
               if (a[i] < min)
               {
                   min = a[i];
                   minpos = i;
               }
               else
               {
                   int diff = a[i] - min;
                   if (diff > maxdiff)
                   {
                       maxdiff = diff;
                       posi = minpos;
                       posj = i;
                   }
               }
           }
           Console.WriteLine("i={0}, j={1}",posi,posj);
       }
*/

class MaxDiffArray {
public:
    static void test() {
        vector<int> arr = { 2,3,5,23,534,3,3,2,1,42,45,36,3,124,1,4,326,4,75,87,10,234234,23,4 };
        MaxDiffArray obj;
        pair<int, pair<int, int>> output = obj.findMaxDiff(arr);
        cout << "Max diff = " << output.first << endl;
        for (auto i = output.second.first; i <= output.second.second; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    pair<int, pair<int, int>> findMaxDiff(vector<int> arr) {
        pair<int, pair<int, int>> result;
        int mnIndex = -1, mxIndex = -1;
        int mn = INT_MAX;
        int maxDiff = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= mn) {
                mn = arr[i];
                mnIndex = i;
            }
            else {
                if (arr[i] - mn > maxDiff) {
                    maxDiff = arr[i] - mn;
                    mxIndex = i;
                }
            }
        }

        return { maxDiff,{mnIndex,mxIndex} };
    }
};