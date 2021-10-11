#pragma once
#include "../Header.h"

class MedianOfTwoSortedArraysOfSameSize {
public:
    static void test() {
        MedianOfTwoSortedArraysOfSameSize obj;

        {
            int ar1[] = { 1, 12, 15, 26, 38 };
            int ar2[] = { 2, 13, 17, 30, 45 };

            int n1 = sizeof(ar1) / sizeof(ar1[0]);
            int n2 = sizeof(ar2) / sizeof(ar2[0]);

            auto res = obj.median2(ar1, ar2, n2);
            cout << "Median = " << res << endl;
        }

        {
            int ar1[] = { 1, 2, 3, 6 };
            int ar2[] = { 4, 6, 8, 10 };
            int n1 = sizeof(ar1) / sizeof(ar1[0]);
            int n2 = sizeof(ar2) / sizeof(ar2[0]);

            auto res = obj.median2(ar1, ar2, n2);
            cout << "Median = " << res << endl;
        }

        {
            int ar1[] = { 1 };
            int ar2[] = { 4 };
            int n1 = sizeof(ar1) / sizeof(ar1[0]);
            int n2 = sizeof(ar2) / sizeof(ar2[0]);

            auto res = obj.median2(ar1, ar2, n2);
            cout << "Median = " << res << endl;
        }

        {
            int ar1[] = { 1,2 };
            int ar2[] = { 4,8 };
            int n1 = sizeof(ar1) / sizeof(ar1[0]);
            int n2 = sizeof(ar2) / sizeof(ar2[0]);

            auto res = obj.median2(ar1, ar2, n2);
            cout << "Median = " << res << endl;
        }

        {
            int ar1[] = { 1,2, 3 };
            int ar2[] = { 4,7,8 };
            int n1 = sizeof(ar1) / sizeof(ar1[0]);
            int n2 = sizeof(ar2) / sizeof(ar2[0]);

            auto res = obj.median2(ar1, ar2, n2);
            cout << "Median = " << res << endl;
        }

        {
            int ar1[] = { 1,4, 6 };
            int ar2[] = { 2,3,5 };
            int n1 = sizeof(ar1) / sizeof(ar1[0]);
            int n2 = sizeof(ar2) / sizeof(ar2[0]);

            auto res = obj.median2(ar1, ar2, n2);
            cout << "Median = " << res << endl;
        }
    }

    double median(int arr1[], int n1, int arr2[], int n2) {
        int p1 = 0, p2 = 0;
        int i = 0, j = 0;
        for (int cnt = 0; cnt <= n1; cnt++) {
            p1 = p2;
            if (i == n1) {
                p2 = arr2[0];
            }
            else if (j == n2) {
                p2 = arr1[0];
            }
            else if (arr1[i] < arr2[j]) {
                p2 = arr1[i++];
            }
            else {
                p2 = arr2[j++];
            }
        }

        return (double)(p1 + p2) / 2.0;
    }

    double median2(int arr1[], int arr2[], int n) {
        if (n == 1) return (double)(arr1[0] + arr2[0]) / 2.0;
        double m1 = median(arr1, n);
        double m2 = median(arr2, n);

        if (m1 == m2) return m1;
        else if (m1 < m2) return median2(arr1 + n / 2, arr2, n - n / 2);
        else return median2(arr1, arr2 + n / 2, n - n / 2);
    }

    double median(int arr[], int n) {
        return (double)(arr[0] + arr[n - 1]) / 2.0;
    }
};