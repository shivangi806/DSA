class Solution {
public:
    
    bool cycle(int node , vector<int>&vis , vector<int>&dvis , vector<int>adj[]){
        vis[node]=1;
        dvis[node]=1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(cycle(it,vis,dvis,adj)) return 1;
            }
            else{
                if(dvis[it]==1) return 1;
            }
        }
        dvis[node]=0;
        return 0;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        // if no cycle then can complete
        vector<int> adj[n];
        for(int i=0;i<p.size();i++){
            int u = p[i][0];
            int v = p[i][1];
            adj[v].push_back(u);
        }
        
        // cycle detect using bfs
        vector<int> vis(n+1 , 0),dvis(n+1,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(cycle(i,vis,dvis,adj)) return 0;
            }
        }
        return 1;
    }
};