class Solution {
public:
    
    int t[201][201];
    int solve(int i , int j , vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return 1e9;
        if(t[i][j]!=-1) return t[i][j] ;
        //if(i==0 && j==0) return grid[i][j];
        int up = grid[i][j] + solve(i-1,j,grid);
        int left = grid[i][j] + solve(i,j-1,grid);
        return t[i][j]= min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
      int n = grid.size();
      int m = grid[0].size();
      memset(t,-1,sizeof(t));
      return solve(n-1,m-1,grid);
      
    }
};