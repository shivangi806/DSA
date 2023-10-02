class Solution {
public:
    
    void dfs(int node , vector<int>&edges,vector<int>&vis ,vector<int>&ans){
        if(ans[node]!=-1) return;
        
        if(vis[node]){
            int len=1;
            int curr = node;
            while(edges[curr]!=node){
                len++;
                curr = edges[curr];
            }
            curr = node;
            while(edges[curr]!=node){
                ans[curr] = len;
                curr = edges[curr];
            }
            ans[curr] = len;
            return;
        }
        vis[node]=1;
        dfs(edges[node] , edges , vis , ans);
        if(ans[node]==-1) ans[node]=ans[edges[node]]+1;
    }
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        
        vector<int> vis(n,0);
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            dfs(i,edges,vis,ans);
        }
        return ans;
    }
};