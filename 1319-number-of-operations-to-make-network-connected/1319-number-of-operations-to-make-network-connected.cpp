class Solution {
public:
    
    void dfs(int i , vector<int> adj[]  , vector<int>&vis){
        vis[i]=1;
        for(auto it : adj[i]){
            if(!vis[it]){
                dfs(it , adj , vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int numedges = edges.size();
        if(numedges < n-1) return -1 ;
        int cc = 0;
        vector<int> vis(n+1);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i , adj , vis);
                cc++;
            }
        }
        return cc - 1;
    }
};