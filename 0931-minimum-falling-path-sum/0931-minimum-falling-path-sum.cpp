class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix,vector<vector<int>>&dp) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        if(i>=n) return 0;
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        
        int x = matrix[i][j] + solve(i+1,max(j-1,0),matrix,dp);
        int y = matrix[i][j] + solve(i+1,j,matrix,dp);
        int z = matrix[i][j] + solve(i+1,min(j+1,n-1),matrix,dp);
        
        return dp[i][j] = min({x,y,z});
    }

    int minFallingPathSum(vector<vector<int>>& mt) {
        int n = mt.size();
        int m = mt[0].size();
        int ans = INT_MAX ;
        vector<vector<int>> dp(n,vector<int>(n,INT_MIN));
        for(int col=0;col<n;col++){
            ans = min(ans , solve(0,col,mt,dp));
        }
        return ans ;
    }
};
