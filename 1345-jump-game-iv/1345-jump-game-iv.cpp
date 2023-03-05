// class Solution {
// public:
    
//     int solve(int i , vector<int>&arr,int n,unordered_map<int,int>&mp){
//         if(i==n-1) return 0;
        
//         int x = solve(i+1,arr,n);
//         int y = solve(i-1,arr,n);
//         auto it = mp.find(arr[i]);
//         int key = it.first;
//         int val = it.second
//         int z = solve()
        
//     }
class Solution {
public:
    int minJumps(vector<int>& arr) 
    {
        int n = arr.size();
        unordered_map<int, vector<int>>mp;
        for (int i = 0; i < n; i++) mp[arr[i]].push_back(i);
        
        queue<int>q;
        vector<bool>visited(n, false);
        q.push(0);
        int steps = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int currIdx = q.front();
                q.pop();
                if (currIdx == n - 1) return steps;
                if (currIdx + 1 < n && !visited[currIdx + 1])
                {
                    visited[currIdx + 1] = true;
                    q.push(currIdx + 1);
                }
                if (currIdx - 1 >= 0 && !visited[currIdx - 1])
                {
                    visited[currIdx - 1] = true;
                    q.push(currIdx - 1);
                }
                for (int newIdx : mp[arr[currIdx]]) 
                {                                
                    if (!visited[newIdx]) 
                    {
                        visited[newIdx] = true;
                        q.push(newIdx);
                    }
                }
                mp[arr[currIdx]].clear();   
            }
            steps++;
        }
        return -1;
    }
};



