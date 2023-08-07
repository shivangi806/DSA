//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
  void dfs(int node ,vector<pair<int,int>>adj[] , vector<int>&vis , stack<int>&st){
    vis[node]=1;
    for(auto it : adj[node]){
        int v = it.first;
        if(!vis[v]){
            dfs(v , adj , vis , st);
        }
    }
    st.push(node);
}


vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
    vector<int> dist(n,INT_MAX);
    vector<pair<int,int>> adj[n];
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int w = it[2];
        adj[u].push_back({v,w});
    }
    
    stack<int> st;
    vector<int> vis(n,0);
    dfs(0,adj,vis,st);
    dist[0]=0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        for(auto it : adj[node]){
            int v = it.first;
            int wt = it.second;
            if(dist[v]>dist[node]+wt){
                dist[v]=dist[node]+wt;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(dist[i]==INT_MAX){
            dist[i]=-1;
        }
    }
    return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends