// class Solution {
// public:
    
    
//     int solve(int i , int k , vector<vector<int>>&piles ,vector<vector<int>>&dp ){
//         if(i>=piles.size() || k==0){
//             return 0;
//         }
//         if(dp[i][k]!=-1) return dp[i][k] ;
//         // choice diagram
//         int maxi = solve(i+1,k,piles,dp);
//         // maxi = max(maxi , notake) ;
//         for(int j=0;j<piles[i].size();j++){
//             if(k-j-1>=0)  maxi = max(maxi , piles[i][j] + solve(i+1 , k-j ,piles,dp));
//         }
        
//         return dp[i][k]=maxi ;
//     }
//     int maxValueOfCoins(vector<vector<int>>& piles, int k) {
//         // it's a kind of n bags with us from in which also we have x number of weights kind of and we need to choose weights such as maximum get but only k number of weigts shud be choosen
        
//         int n = piles.size();
//         int m = piles[0].size();
//         // first need of prefix sum
//         for(int i=0;i<piles.size();i++){
//             for(int j=1;j<piles[0].size();j++){
//                 piles[i][j]=piles[i][j-1]+piles[i][j];
//             }
//         }
//         vector<vector<int>> dp(n+2, vector<int>(k+2 , -1));
//         return solve(0,k,piles,dp);
//     }
// };


class Solution {
public:
    int solve(vector<vector<int>> &v,vector<vector<int>> &dp,int j,int k,int &n){
        if(j>=n)return 0;
        if(k==0)return 0;
        if(dp[j][k] != -1)return dp[j][k];
        int mx = solve(v,dp,j+1,k,n);
        int temp = 0;
        for(int i = 0; i < v[j].size(); i++){
            temp += v[j][i];
            if(k-i-1 >= 0){
                mx = max(mx,temp+solve(v,dp,j+1,k-i-1,n));
            }
        }
        return dp[j][k] = mx;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
        return solve(piles,dp,0,k,n);
    }
};