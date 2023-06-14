class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i , int pi ,int n, vector<int>&nums){
        if(i>=n) return 0;
        
        if(dp[i][pi+1]!=-1) return dp[i][pi+1];
        
        int no = solve(i+1 , pi , n , nums);
        int yes = INT_MIN;
        if(pi==-1 || nums[i]>nums[pi]){
            yes = 1 + solve(i+1 , i ,n , nums);
        }
        return dp[i][pi+1]=max(no , yes);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,vector<int>(n+1 , -1));
        return solve(0,-1,n,nums);
    }
};