class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<n;j++){
            dp[0][j] = matrix[0][j] ;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                 int up , leftd=matrix[i][j], rightd=matrix[i][j] ;
                  up = dp[i-1][j] + matrix[i][j] ;
                 if(j>0)  leftd +=dp[i-1][j-1] ;
                 else leftd+=1e9;
                
                 if(j<m-1)  rightd+= dp[i-1][j+1] ;
                 else rightd += 1e9 ;
                 dp[i][j] = min({up,leftd,rightd});
            }
        }
        int ans = INT_MAX;
        for(int j=0;j<m;j++){
            ans = min(ans , dp[n-1][j]);
        }
        return ans ;
    }
};