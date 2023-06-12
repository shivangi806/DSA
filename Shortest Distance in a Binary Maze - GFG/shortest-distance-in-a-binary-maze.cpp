//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        if(source.first==destination.first && source.second==destination.second) return 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int , pair<int,int>>> q;
        vector<vector<int>> distance(n , vector<int>(m,1e9));
        distance[source.first][source.second]=0;
        q.push({0,{source.first , source.second}});
        int dr[]={1,-1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(int i=0;i<4;i++){
                int nr = dr[i]+r;
                int nc = dc[i]+c;
                
                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1 && dis+1< distance[nr][nc]){
                    distance[nr][nc]=dis+1;
                    if(nr==destination.first && nc==destination.second){
                        return dis+1;
                    }
                    q.push({1+dis  , {nr,nc}});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends