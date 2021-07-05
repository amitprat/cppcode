#pragma once
#include "../Header.h"

/*
Ok heres the solution. SantiagoYMG is pretty close.
The solution is O(n) in time complexity.

Make all of them stand in a row.
Lets say the people are a,b,c,d,e,f,g,h,i,j,.......n

Compare a and b.
if a knows b => a is certainly not the celebrity. Probable celebrity = b
if a doesnt know b => b is certainly not the celebrity. Probable celebrity = a

In either case compare the probable celebrity to the next person in line ie 'c' and repeat the process. Each comparison should eliminate 1 person and have another as the probable celebrity. At the end, the probable celebrity who survives is the certain celebrity.

Complexity = O(n)
*/
class CelebrityProblem {
public:
    static void test() {
        CelebrityProblem obj;
        vector<vector<int>> mat = {
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0},
            {0, 0, 1, 0}
        };
        cout << obj.findCelebrity(mat, 4) << endl;
    }

    int findCelebrity(vector<vector<int>>& mat, int m) {
        int a = 0, b = m - 1;
        while (a < b) {
            if (knows(mat, a, b)) a++;
            else b--;
        }

        return validateCelebrity(mat, a);
    }

    bool knows(vector<vector<int>>& mat, int a, int b) {
        return mat[a][b];
    }

    int validateCelebrity(vector<vector<int>>& mat, int a) {
        // if celerity knows anyone
        for (int j = 0; j < mat[a].size(); j++) if (a != j && mat[a][j]) return -1;
        // if anyone else doesn't know celeb
        for (int i = 0; i < mat[a].size(); i++) if (a != i && !mat[i][a]) return -1;

        return a;
    }
};