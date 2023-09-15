class Solution {
public:
    
    int minimumSpanning(vector<pair<int,int>> adj[],int n){
      priority_queue<pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>>> pq;
      pq.push({0,0});// wt , node
      vector<int> vis(n,0);
      int sum=0;
      while(!pq.empty()){
          int node = pq.top().second;
          int weight = pq.top().first;
          pq.pop();
          if(vis[node]) continue;
          sum+=weight;
          vis[node]=1;
          for(auto it : adj[node]){
              int adjNode=it.first;
              int adjWeight = it.second;
              
              if(!vis[adjNode]){
                  pq.push({adjWeight , adjNode});
              }
          }
      }
      return sum;
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