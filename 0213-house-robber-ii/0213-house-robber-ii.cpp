class Solution {
public:
    int solve(int n , vector<int>&nums,vector<int>&dp){
    if(n==0) return nums[0];
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    // pick or non pick condition with given constraints
    // if we pick that element then we need to add it's value 
    // int maxi = INT_MIN ;
    int left = nums[n] + solve(n-2,nums,dp);
    int right = solve(n-1,nums,dp);
    return dp[n]=max(left,right);
}
int rob(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int> dp1(n+1,-1),dp2(n+1,-1);
    if(n==1) return nums[0];
    vector<int> temp1 , temp2;
    for(int i=0;i<n;i++){
        if(i!=0)
        temp1.push_back(nums[i]);
        
        if(i!=n-1)
        temp2.push_back(nums[i]);
    }
    
    return max(solve(n-2,temp1,dp1),solve(n-2,temp2,dp2));
}
};