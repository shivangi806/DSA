//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int solve(int i , int buy , int p[],int c,vector<vector<vector<int>>>&dp,int n){
        if(i==n) return 0;
        
        if(c==0) return 0;
        
        if(dp[i][buy][c]!=-1) return dp[i][buy][c] ;
        int ans =0;
        if(buy){
            int x = -p[i] + solve(i+1,0,p,c,dp,n);
            int y = solve(i+1,1,p,c,dp,n);
            
            ans = max(x,y);
        }
        else{
            int x = p[i]+solve(i+1,1,p,c-1,dp,n);
            int y = solve(i+1,0,p,c,dp,n);
            
            ans = max(x ,y);
        }
        return dp[i][buy][c] =  ans ;
    }
    int maxProfit(int k, int n, int A[]) {
       vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(2,vector<int>(k+1,-1)));
       return solve(0,1,A,k,dp,n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends