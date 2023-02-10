class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n =grid.size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                   q.push({i,j});
                }
            }
        }
        int res = 0;
        while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            vector<pair<int , int>> v = {{0,1},{0,-1},{1,0},{-1,0}};
            for(auto it : v){
                int x = a+ it.first;
                int y = b+ it.second;
                if(x>=0 && y>=0 && x < n && y < n && grid[x][y]==0){
                 q.push({x,y});
                 grid[x][y] =  grid[a][b] + 1;
                 res = max(res , grid[x][y]);
                }
            }
        }
        return res-1 ;
    }
};