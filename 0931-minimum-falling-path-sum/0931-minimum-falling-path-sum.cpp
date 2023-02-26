class Solution {
public:
    
    
    int solve (int i , int j , vector<vector<int>>&matrix , vector<vector<int>>&dp){
        int n = matrix.size();
        int m = matrix[0].size();
        
        if(j<0 || j>m-1) return 1e9 ;
        if(i==n-1) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int x1 = matrix[i][j] + solve(i+1,j,matrix,dp); // for down
        int x2 = matrix[i][j] + solve(i+1,j-1,matrix,dp); // for left diag
        int x3 = matrix[i][j] + solve(i+1,j+1,matrix,dp); // for right diag
        return dp[i][j]= min({x1,x2,x3});
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = INT_MAX ;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int col=0;col<m;col++){
            ans = min(ans , solve(0,col,matrix,dp));
        }
        return ans ;
    }
};