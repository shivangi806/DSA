//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
    }
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
    vector<int> distance(n+1,INT_MAX);
    pq.push({0,1});
    distance[1]=0;
    vector<int> parent(n+1);
    for(int i=1;i<=n;i++) parent[i]=i;
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;

        pq.pop();
        for(auto it : adj[node]){
            int adwt=it.second;
            int adjnode = it.first;
            if(dis+adwt < distance[adjnode]){
                distance[adjnode]=dis+adwt;
                pq.push({dis+adwt,adjnode});
                parent[adjnode]=node;
            }
        }
    }
    if(distance[n]==INT_MAX){
        return {-1};
    }
    vector<int> path;
    int temp=n;
        while(parent[temp]!=temp){
            path.push_back(temp);
            temp=parent[temp];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path ;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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