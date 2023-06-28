class Solution {
public:
    
    int solve(int i , int j  ,vector<int>&nums ,vector<vector<int>>&dp){
        if(i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j] ;
        int ans=INT_MIN ;
        for(int k=i;k<=j;k++){
            int temp = nums[i-1]*nums[k]*nums[j+1] + solve(i,k-1,nums,dp)+solve(k+1,j,nums,dp);
            ans = max(ans , temp);
        }
        
        return dp[i][j] = ans ;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin() , 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n+3,vector<int>(n+3,-1));
        return solve(1 , n-2,nums,dp);
    }
};