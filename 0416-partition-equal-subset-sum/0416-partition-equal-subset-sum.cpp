class Solution {
public:
    
    bool solve(int i , int n , vector<int>&nums,int tg, vector<vector<int>>&dp){
        if(tg==0) return 1;
        if(i==n-1){
            if(tg==nums[i]) return 1;
            return 0;
        }
        
        if(dp[i][tg]!=-1) return dp[i][tg] ;
        bool notake = solve(i+1,n,nums,tg,dp);
        bool take = 0;
        if(tg-nums[i]>=0) take = solve(i+1,n,nums,tg-nums[i],dp);
        
        return dp[i][tg] = (take || notake) ;
    }
    bool canPartition(vector<int>& nums){
        int n = nums.size();
        int tg=0;
        for(int i=0;i<n;i++) tg+=nums[i];
        if(tg%2!=0) return 0;
        vector<vector<int>> dp(n+1,vector<int>(tg+1,-1));
        return solve(0,n,nums,tg/2,dp);
    }
};