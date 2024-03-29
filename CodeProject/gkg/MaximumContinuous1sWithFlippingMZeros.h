#include "../Header.h"

/*
You are given with an array of 1s and 0s. And you are given with an integer m, which signifies number of flips allowed.

find the position of zeros which when flipped will produce maximum continuous series of 1s.

e.g.
input:
arr={1 1 0 1 1 0 0 1 1 1 } m=1
output={1 1 1 1 1 0 0 1 1 1} position=2

arr={1 1 0 1 1 0 0 1 1 1 } m=2
output={1 1 0 1 1 1 1 1 1 1} position=5,6
*/

/*
I would use SLIDING WINDOW for this problem. (Just realized that I have used it at least 3 times at careercup!)

Lets use a window covering from index wL to index wR. Let the number of zeros inside the window be nZero. We try to maintain the window with at most m zeros inside.

The main steps are:
- While nZero is no more than m: expand the window to the right (wR++) and update the count nZero;
- While nZero exceeds m, shrink the window from left (wL++), update nZero;
- Update the widest window along the way. The positions of must-flip zeros are inside the best window.

This solution assumes we can use m or less number of flips.
Time complexity = O(n), space = O(1).

Pseudo-code:
*/

/*

wL = 0; wR = 0; 
nZero = 0;
bestWindowWidth = -1;

while(wR < A.length()){	
	//expand to the right, update '0' count:
	if (nZero <= m){
		wR++;
		if (A[wR] == '0') nZero++; 
	};

	//shrink from left, update '0' count:
	if (nZero > m){ 
		if (A[wL] == '0') nZero--;
		wL++;
	};
	
	//update best window:
	if (wR - wL > bestWindowWidth){
		bestWindowWidth = wR - wL;
		bestWR = wR;
		bestWL = wL;
	};	
};

*/