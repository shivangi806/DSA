class Solution {
public:
    bool solve(int i , vector<int>&nums , int tg,vector<vector<int>>&dp){
        if(tg==0) return 1;
        if(i>=nums.size()) return 0;
        
        if(dp[i][tg]!=-1) return dp[i][tg] ;
        bool t =0;
        if(tg-nums[i]>=0) t = solve(i+1,nums,tg-nums[i],dp);
        bool nt = solve(i+1 , nums , tg,dp);
        
        return dp[i][tg] = t || nt ;
    }
    bool canPartition(vector<int>& nums) {
        /// s1+s2 = s;
        // s1=s/2;
        // find subset whose sum is s/2
        int n = nums.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        if(sum%2!=0) return 0;
        vector<vector<int>> dp(n+1 , vector<int>(sum+1 , -1));
        return solve(0,nums,sum/2,dp);
    }
};