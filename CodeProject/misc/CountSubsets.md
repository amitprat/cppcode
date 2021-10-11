###Given an int array without repeated elements and a target, count the total number of subset that can be generated from the array such that min (subset) + max (subset) < target
https://careercup.com/question?id=5091778836299776

```java
public int countSubSet(int[] nums, int target){

}
```

Sort the array, then use two pointers to count subsets.

```java
public static int countSubSet(int[] nums, int target){
    if(nums.length==0)
        return 0;
     
    Arrays.sort(nums);
    int subsets=0;
    int start=0, end=nums.length-1;

    while(start<=end){
        if(2*nums[start]>=target)
            return subsets;
        if(nums[start]+nums[end]<target){
            if(start==end)
                subsets=subsets+1;
            else
                subsets= subsets+(int)Math.pow(2,end-start-1);

            start++;
        }
        else
            end--;
    }
    
    return subsets;
}
```
