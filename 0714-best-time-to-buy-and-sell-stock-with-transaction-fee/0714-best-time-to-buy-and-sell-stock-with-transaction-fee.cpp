class Solution {
public:
    int dp[100005][3];
    int solve(int i , int canbuy , vector<int>&p,int fee){
        if(i==p.size()){
            return 0;
        }
        
        if(dp[i][canbuy]!=-1) return dp[i][canbuy];
        int ans = 0 ;
        if(canbuy==1){
            int buykaro = -p[i] + solve(i+1 ,0, p,fee);
            int nibuykaro = solve(i+1,1,p,fee);
            
            ans=max(buykaro,nibuykaro);
        }
        else{
            int sellkaro = p[i]+solve(i+1,1,p,fee)-fee;
            int nisellkaro = solve(i+1,0,p,fee);
            ans = max(sellkaro,nisellkaro);
        }
        return dp[i][canbuy] = ans ;
    }
    int maxProfit(vector<int>& p, int fee) {
        int n = p.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,1,p,fee);
    }
};