class Solution {
public:
    int n ;
    int solve(int i , int k , vector<int>&arr , vector<int>&dp){
        if(i>=n) return 0;
        
        if(dp[i]!=-1) return dp[i];
        int tempmaxi=0,ans=0;
        int lsum=0;
        for(int j =i;j<min(i+k , n);j++){
            tempmaxi = max(tempmaxi , arr[j]);
            lsum = tempmaxi*(j-i+1) + solve(j+1 , k, arr , dp);
            ans = max(ans , lsum);
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n=arr.size();
        vector<int> dp(n+1 , -1);
        return solve(0,k,arr,dp);
    }
};