class Solution {
public:
    bool valid(int i , int j , vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j]!=0){
            return 0;
        }
        return  1;
    }
    // void dfs1(int i , int j ,vector<vector<int>>& grid){
    //     int n = grid.size();
    //     int m = grid[0].size();
    // }
    void dfs(int i , int j , vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        
        grid[i][j]=2;// kind of showing visited 
        if(valid(i+1,j,grid)) dfs(i+1,j,grid);
        if(valid(i-1,j,grid)) dfs(i-1,j,grid);
        if(valid(i,j+1,grid)) dfs(i,j+1,grid);
        if(valid(i,j-1,grid)) dfs(i,j-1,grid);
    }
    int closedIsland(vector<vector<int>>& grid) {
        // do not consider boundaries vale 0's
        int n = grid.size();
        int m = grid[0].size();
        
        for(int j=0;j<m;j++){
            if(grid[0][j]==0){
                dfs(0,j,grid);
            }
            if(grid[n-1][j]==0){
                dfs(n-1,j,grid);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                dfs(i,0,grid);
            }
            if(grid[i][m-1]==0){
                dfs(i,m-1,grid);
            }
        }
        cout<<9<<endl;
        // yha tk ab manipulate ho gya hoga sara boundaries se connnected
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    dfs(i,j,grid);
                    c++;
                }
            }
        }
        return c ;
    }
};