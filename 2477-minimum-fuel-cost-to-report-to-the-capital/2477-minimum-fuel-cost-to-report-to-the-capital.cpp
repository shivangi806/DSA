class Solution {
public:
    long long ans =0;
     long long dfs(int node , vector<int> adj[] , vector<int>&vis , int seats){
        vis[node]=1;
        long long c=1;
        for(auto it : adj[node]){
            if(!vis[it])
            c+=dfs(it,adj , vis , seats);
        }
        
        int x = c/seats ;
        if(c%seats) x++;
        if(node!=0)ans+=x;
        return c;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<int> adj[n+1];
        
        for(auto it : roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n+1 , 0);
        dfs(0,adj,vis,seats);
        return ans ;
    }
};