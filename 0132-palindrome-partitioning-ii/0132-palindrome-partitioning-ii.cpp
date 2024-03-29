class Solution {
public:
    int n ;
    bool pal(string &s , int i , int j){
        while(i<j){
            if(s[i++]!=s[j--]) return 0;
        }
        return 1;
    }
    int solve(string &s ,int i,vector<int>&dp){
        if(i>=n-1) return 0;
        if(dp[i]!=-1) return dp[i];
        if(pal(s,i,n-1)) return 0;
        int ans = INT_MAX ;
        for(int k=i;k<n;k++){
            if(pal(s,i,k)){
                int temp = 1 + solve(s,k+1,dp);
                ans = min(ans , temp);
            }
        }
        return dp[i] = ans ;
    }
    int minCut(string s) {
        n=s.size();
        vector<int> dp(n+1,-1);
        return solve(s,0,dp); 
    }
};