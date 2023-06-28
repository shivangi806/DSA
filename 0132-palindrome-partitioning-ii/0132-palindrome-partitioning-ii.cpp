class Solution {
public:
    int n ;
    bool pal(string &s , int i , int j){
        while(i<j){
            if(s[i]!=s[j]) return 0;
            i++,j--;
        }
        return 1;
    }
    int solve(string &s ,int i,vector<int>&dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = 1e6;
        for(int k=i;k<n;k++){
            if(pal(s,i,k)){
                int temp = 1 + solve(s,k+1,dp);
                ans = min(ans , temp);
            }
        }
        return dp[i] = ans ;
    }
    int minCut(string s) {
        n=s.size();
        vector<int>dp(n,-1);
        // dp.resize(n+1,-1);
        if(pal(s,0,n-1)) return 0;
        return solve(s,0,dp)-1; 
    }
};





// class Solution {
// public:
//     int palin(int i,int j,string &t){
//         while(j>i){
//             if(t[i]!=t[j])return 0;
//             i++;j--;
//         }
//         return 1;
//     }
//     int findans(string &s,vector<int>&dp,int i,int n){
//         if(i==n)return 0;
//         if(dp[i]!=-1)return dp[i];
//         int mini = 1e6;
//         for(int k = i;k<n;k++){
//              if(palin(i,k,s)){
//                   int cost = 1 + findans(s,dp,k+1,n);
//                   mini = min(mini,cost);
//              }
//         }
//         return dp[i] = mini;
//     }
//     int minCut(string s) {
//         int n = s.size();
//         vector<int>dp(n,-1);
//         if(palin(0,n-1,s))return 0;
//         return findans(s,dp,0,n)-1;
//     }
// };