class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i ,int j, vector<int>&coins ,int n){
        if(j==0) return 0;
        if(i==n-1){
            if(j%coins[i]==0){
                return j/coins[i];
            }
            return 1e9;
        }
        if(dp[i][j]!=-1) return dp[i][j] ;
        int notake = solve(i+1 ,j,coins,n);
        int take = INT_MAX;
        if(j-coins[i]>=0)
        take = 1 + solve(i , j-coins[i] ,coins,n);
        return dp[i][j]=min(take,notake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.resize(n+1,vector<int>(amount+1,-1));
        int ans = solve(0,amount,coins,n);
        if(ans>=1e9) return -1;
        return solve(0,amount,coins,n);
    }
};