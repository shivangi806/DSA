class Solution {
public:
    
    int minimumSpanning(vector<pair<int,int>> adj[],int n){
      priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
      pq.push({0,0});
      vector<int> vis(n,0);
      int sum=0;
      while(!pq.empty()){
        int dis = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        sum+=dis;
        for(auto it : adj[u]){
          int v = it.first;
          int dd = it.second;
          if(!vis[v]){
            pq.push({dd,v});
          }
        }
      }
      return sum ;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector < pair < vector<int> , int > > grp(n);
        for(int i=0;i<n;i++){
            grp[i] = {points[i] , i};
        }
        vector<pair<int,int>> adj[n+1];
        int sum=0;
        for(int i=0;i<n;i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=0;j<n;j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                int wt = abs(x2-x1)+abs(y1-y2);
                adj[grp[i].second].push_back({grp[j].second,wt});
                adj[grp[j].second].push_back({grp[i].second , wt});
            }
        }
        return minimumSpanning(adj,n);
    }
};