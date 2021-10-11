### Find min number of jumps it will take to reach to the top in snake and ladder game using recursive function

```cpp
int minJumpsTest() {
    int n = 5, m = 6;
    int end = n*m;
    unordered_map<int> jumps;
    jumps[5] = 12;
    ....

    int start = 1;
    unordered_set<int> visited;
    auto res = minJumpsDFS(start, end, jumps,visited);
}

int minJumpsDFS(int start, int end, unordered_map<int> jumps,unordered_set<int>& visited)
{
    if(start == end) return 0;
    visited[start] = true;
    int mn = INT_MAX;
    for(int k=start+1;k<=end && k<start+6;k++) {
        int target = k;
        if(jumps.find(k) != jumps.end()) target = jumps[k];
        if(!visited[target])
            mn = min(mn, 1+minJumps(target, end, jumps));
    }

    return mn;
}

int minJumpsBFS(int n, unordered_map<int> jumps)
{
    queue<pair<int,int>> q;
    q.push({1, 0});
    unordered_set<int> visited;
    visited.insert(1);

    while(!q.empty()) {
        auto f = q.front(); q.pop();
        if(f.first == n) return f.second;

        for(int k=f.first+1;k<=n && k<f.first+6;k++) {
            int target = k;
            if(jumps.find(k) != jumps.end()) target = jumps[k];

            if(!visited[target]) {
                q.push({target, f.second+1});
                visited[target] = true;
            }
        }
    }
}
```