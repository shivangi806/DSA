//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i , int n , int a[],int j,vector<vector<int>>&dp){
        if(i>=n) return 0;
        if(dp[i][j+1]!=-1) return dp[i][j+1];
        int tk = 0;
        int nt = 0;
        if(j==-1 || abs(a[j]-a[i])==1) tk = 1+ solve(i+1,n,a,i,dp);
        nt = solve(i+1,n,a,j,dp);
        
        return dp[i][j+1] = max(tk,nt);
    }
    int longestSubsequence(int n, int a[])
    {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,n,a,-1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends