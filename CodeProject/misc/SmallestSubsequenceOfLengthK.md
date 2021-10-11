*Given an array of n integers, find the lexicographically smallest subsequence of length k.*

I feel this question can be solved by stack. once we found previous element in the stack is larger than current element, than pop out

```cpp
// Exponential time
void smallestSubsequence(vector<int> nums, int index, string& smallest, string cur, int k)
{
    if(k == 0) {
        if(cur < smallest) smallest = cur;
        return;
    }
    if(index >= nums.size()) return;

    smallestSubsequence(nums, index+1, smallest, cur + to_string(nums[index]), k-1);

    smallestSubsequence(nums, index+1, smallest, cur, k);
}
```

Another approach using stack

```cpp
void smallestSubsequence(vector<int> nums, int k) {
    stack<char> st;

    int l = nums.size();
    int index = 0;
    for(auto num : nums) {
        char ch = tochar(num);
        if(st.size() < k) {
            st.push(ch);
        } else {
            int rem = l - index - 1;
            int needed = 1;
            while(!st.empty() && num < st.top() && rem >= needed) {
                st.pop();
                needed++;
            }
            st.push(ch);
        }

        index++;
    }
}
```