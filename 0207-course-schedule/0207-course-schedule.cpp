class Solution {
public:
    
    bool detectCycle(int n ,vector<int> adj[] , vector<int>&vis,vector<int>&dfsvis,int idx){
        vis[idx]=1;
        dfsvis[idx]=1;
        for(auto it : adj[idx]){
            if(!vis[it]){
//return detectCycle(n,p,vis,dfsvis,it);
                if(detectCycle(n,adj,vis,dfsvis,it)) return true;
            }
            else{
                if(dfsvis[it]){
                    return true;
                }
            }
        }
        dfsvis[idx]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        // cycle detection in directed graph concept
        // dfs traversal karte h 
        // vis and dfsvisit lenge
        vector<int> adj[n+1];
        for(auto it : p){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>vis(n+1,0),dfsvis(n+1,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(detectCycle(n,adj,vis,dfsvis,i)) return false;
            }
        }
       return true; 
    }
};