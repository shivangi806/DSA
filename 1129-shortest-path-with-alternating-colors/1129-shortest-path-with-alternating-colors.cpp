class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int, int>> adj[n];
        for(auto it : redEdges){
            adj[it[0]].push_back({it[1],1});
        }
        for(auto it : blueEdges){
            adj[it[0]].push_back({it[1],2});
        }
        vector<vector<int>> dist(n,vector<int>(3,INT_MAX));
        queue<pair<int,int>> q;
        q.push({0,0});
        dist[0][0]=0;
        while(!q.empty())
        {
            int node = q.front().first;
            int pvColor =q.front().second;
            q.pop();
            for(auto it : adj[node])
            {
                int adjnode = it.first;
                int color = it.second;
                if(color == pvColor) continue;
                if(dist[adjnode][color] == INT_MAX){
                    dist[adjnode][color] = dist[node][pvColor]+1;
                    q.push({adjnode, color});
                }
            }
        } 
       vector<int> res(n,0);
        for(int i=1;i<n;i++){
            res[i]=min(dist[i][1] , dist[i][2]);
            if(res[i]==INT_MAX){
                res[i]=-1;
            }
        }
        return res;
    }
};