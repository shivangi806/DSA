class Solution {
public:
    
    int solve(int i , int buy , vector<int>&p, vector<vector<int>>&dp){
        if(i>=p.size()) return 0;
        
        if(dp[i][buy]!=-1) return dp[i][buy];
        
        int ans =0;
        if(buy){
            int will = -p[i] + solve(i+1,0,p,dp);
            int willnot = solve(i+1,1,p,dp);
            
            ans = max(will , willnot);
        }
        else{
            int will = p[i] + solve(i+2,1,p,dp);
            int willnot = solve(i+1,0,p,dp);
            
            ans = max(will,willnot);
        }
        
        return dp[i][buy] = ans ;
    }
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(0,1,p,dp);
    }
};