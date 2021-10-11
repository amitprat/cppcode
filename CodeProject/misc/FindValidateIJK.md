# Given a array of integers , find 3 indexes i,j,k such that, i<j<k and a[i] < a[j] < a[k]. Best possible is a O(n) algorithm.

```java
a[i]<a[j]<a[k] s.t i<j<k
From the original array build two arrays.
i) LMin[i] contains index of the min element seen so far from the left including a[i].
ii) RMax[i] contains index of the max element seen so far from the right including a[i].
consider the following array:
a =4,7,5,1,3,8,9,6,2
LMin=0,0,0,3,3,3,3,3,3
RMax=6,6,6,6,6,6,6,7,8
```

```cpp
void print(vector<int>& arr) {
    for(int i=0;i<n;i++) left[i] = i > 0 ? min(left[i-1],arr[i]) : arr[i];
    for(int i=n-1;i>=0;i--) right[i] = ...;

    for(int i=0;i<n;i++) {
        if(left[i] < arr[i] && right[i] > arr[i]) {
            cout<<left[i]<<" "<<arr[i]<<right[i]<<endl;
        }
    }
}
```


