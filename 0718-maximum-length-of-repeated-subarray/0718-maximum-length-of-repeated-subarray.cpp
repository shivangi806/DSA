class Solution {
public:
    int n , m ;
    int lcs(int i , int j , vector<int>&nums1 , vector<int>&nums2 , vector<vector<int>>&dp){
        if(i>=n || j>=m) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int ans =0;
        if(nums1[i]==nums2[j]){
            ans = 1+lcs(i+1,j+1,nums1,nums2,dp);
        }
        return dp[i][j]=ans ;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        int ans = 0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans , lcs(i,j,nums1,nums2,dp));
            }
        }
        return ans ;
    }
};