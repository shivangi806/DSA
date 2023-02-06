class Solution {
public:
    bool valid(int i , int j ,vector<vector<int>>& grid,int n,int m){
        if(i>=0 && j>=0 && i<n && j<m && grid[i][j]==1){
            return 1;
        }
        return 0;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int time=0;
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0) return 0;
        
        while(!q.empty()){
            int len = q.size();
            int temp =0;
            while(len!=0){
                pair<int,int> p = q.front();
                q.pop();
                int x1 = p.first;
                int y1 = p.second;
                
                int u[4]={0,0,1,-1};
                int v[4]={1,-1,0,0};
                for(int i=0;i<4;i++){
                    int x = u[i]+x1;
                    int y = v[i]+y1;
                    
                    if(valid(x,y,grid,n,m)){
                        temp++;
                        grid[x][y]=2;
                        q.push({x,y});
                    }
                }
                len--;
            }
            
            if(temp!=0)time++;
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
};