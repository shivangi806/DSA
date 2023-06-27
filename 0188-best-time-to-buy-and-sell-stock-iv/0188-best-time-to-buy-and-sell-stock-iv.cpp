class Solution {
public:
     int solve(int i , int buy , vector<int>&p,int c,vector<vector<vector<int>>>&dp){
        if(i==p.size()) return 0;
        
        if(c==0) return 0;
        
        if(dp[i][buy][c]!=-1) return dp[i][buy][c] ;
        int ans =0;
        if(buy){
            int x = -p[i] + solve(i+1,0,p,c,dp);
            int y = solve(i+1,1,p,c,dp);
            
            ans = max(x,y);
        }
        else{
            int x = p[i]+solve(i+1,1,p,c-1,dp);
            int y = solve(i+1,0,p,c,dp);
            
            ans = max(x ,y);
        }
        return dp[i][buy][c] =  ans ;
    }
    int maxProfit(int k, vector<int>& p) {
       int n = p.size();
       vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(2,vector<int>(k+1,-1)));
       return solve(0,1,p,k,dp);
    }
};