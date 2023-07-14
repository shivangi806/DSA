class Solution {
public:
    
    vector<vector<int>> dp;
    int solve(int i , int j , string &s,string &t){
        if(j<0) return 1;
        if(i<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int ans =0;
        if(s[i]==t[j]){
            ans = solve(i-1,j-1,s,t)+solve(i-1,j,s,t);
        }
        else ans = solve(i-1,j,s,t);
        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return solve(n-1,m-1,s,t);
    }
};