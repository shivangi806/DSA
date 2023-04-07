class Solution {
public:
    bool valid(int i , int j , vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j]!=1){
            return 0;
        }
        return  1;
    }
    void dfs(int i , int j , vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        
        grid[i][j]=0;// kind of showing visited 
        if(valid(i+1,j,grid)) dfs(i+1,j,grid);
        if(valid(i-1,j,grid)) dfs(i-1,j,grid);
        if(valid(i,j+1,grid)) dfs(i,j+1,grid);
        if(valid(i,j-1,grid)) dfs(i,j-1,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        // boundary se connected sare 1's ko 0 kr do
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int j=0;j<m;j++){
            if(grid[0][j]==1){
                dfs(0,j,grid);
            }
            if(grid[n-1][j]==1){
                dfs(n-1,j,grid);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                dfs(i,0,grid);
            }
            if(grid[i][m-1]==1){
                dfs(i,m-1,grid);
            }
        }
        
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    c++;
                }
            }
        }
        return c ;
    }
};