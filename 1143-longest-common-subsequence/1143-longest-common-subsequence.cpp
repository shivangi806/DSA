class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(int i , int j , string &s1 , string &s2 ){
        if(i==0 || j==0) return 0;
        
        if(dp[i-1][j-1]!=-1) return dp[i-1][j-1];
        if(s1[i-1]==s2[j-1]){
            return dp[i-1][j-1] =  1 + solve(i-1,j-1,s1,s2);
        }
        else return dp[i-1][j-1] =  max(solve(i-1,j,s1,s2) , solve(i ,j-1 , s1,s2));
        return dp[i-1][j-1] ;
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        dp.resize(n,vector<int>(m , -1));
        return solve(n,m,text1,text2);
    }
};