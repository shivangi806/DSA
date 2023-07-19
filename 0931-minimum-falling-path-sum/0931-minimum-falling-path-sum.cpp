class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix,vector<vector<int>>&dp) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // if(i<0 || j<0 || i>=n || j>=m) return INT_MIN;
        if(i>=n) return 0;
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        
        int x = matrix[i][j] + solve(i+1,max(j-1,0),matrix,dp);
        int y = matrix[i][j] + solve(i+1,j,matrix,dp);
        int z = matrix[i][j] + solve(i+1,min(j+1,n-1),matrix,dp);
        
        return dp[i][j] = min({x,y,z});
       
       // return dp[i][j] = matrix[i][j] + min({solve(i+1, max(0, j-1), matrix,dp),solve(i+1, j, matrix, dp),solve(i+1, min(n-1, j+1), matrix, dp)});
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
// class Solution {
// public:
//     int minFallingPathSumUtil(int row, int col, vector<vector<int>>& matrix, int n, vector<vector<int>>& dp) {

//     if(row >= n) return 0;

//     if(dp[row][col] != INT_MIN) return dp[row][col];

//     return (dp[row][col] = matrix[row][col] + min({
//        minFallingPathSumUtil(row+1, max(0, col-1), matrix, n, dp),
//        minFallingPathSumUtil(row+1, col, matrix, n, dp),
//        minFallingPathSumUtil(row+1, min(n-1, col+1), matrix, n, dp)
//     }));

// }
// int minFallingPathSum(vector<vector<int>>& matrix) {

//     int n = matrix.size();

//     vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
//         int mini = INT_MAX;
//         for(int i = 0; i < n; i++) { 

//             mini = min(mini, minFallingPathSumUtil(0, i, matrix, n, dp));
//         }

//         return mini;
//     }
// };