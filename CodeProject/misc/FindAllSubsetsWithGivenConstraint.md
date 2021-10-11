## Find subsets

*// For a given vector of integers and integer K, find the number of non-empty subsets S such that min(S) + max(S) <= K
// For example, for K = 8 and vector [2, 4, 5, 7], the solution is 5 ([2], [4], [2, 4], [2, 4, 5], [2, 5])
The time complexity should be O(n2). Approach and code was asked*

Can be solved using 2 Pointers technique. Complexity - O(n logn) for sorting. If the data is sorted then O(n)


```java
    sort(V.begin(), V.end());
    int p1 = 0,p2 = V.size()-1;
    int ans = 0;
    while(p1<=p2)
    {
        if(V[p1] + V[p2] > k)
        {
            p2--;
        }
        else
        {
            ans = ans + 1<<(p2 -p1);
            p1++;
        }
    }
```