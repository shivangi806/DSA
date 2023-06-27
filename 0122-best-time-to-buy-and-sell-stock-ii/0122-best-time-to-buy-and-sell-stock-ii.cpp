class Solution {
public:
    
    int dp[100005][3];
    int solve(int i , int canbuy , vector<int>&p){
        if(i==p.size()){
            return 0;
        }
        
        if(dp[i][canbuy]!=-1) return dp[i][canbuy];
        int ans = 0 ;
        if(canbuy==1){
            int buykaro = -p[i] + solve(i+1 ,0, p);
            int nibuykaro = solve(i+1,1,p);
            
            ans=max(buykaro,nibuykaro);
        }
        else{
            int sellkaro = p[i]+solve(i+1,1,p);
            int nisellkaro = solve(i+1,0,p);
            ans = max(sellkaro,nisellkaro);
        }
        return dp[i][canbuy] = ans ;
    }
    int solvetb(vector<int>& p){
        int n = p.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                
                if(j==1){
                int buykaro = -p[i] + dp[i+1][0];
                int nibuykaro = dp[i+1][1];

                dp[i][j]=max(buykaro,nibuykaro);
                }
                else{
                    int sellkaro = p[i]+dp[i+1][1];
                    int nisellkaro = dp[i+1][0];
                    dp[i][j] = max(sellkaro,nisellkaro);
                }
            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& p) {
        int n = p.size();
        // memset(dp,-1,sizeof(dp));
        // return solve(0,1,p);
        return solvetb(p);
    }
};