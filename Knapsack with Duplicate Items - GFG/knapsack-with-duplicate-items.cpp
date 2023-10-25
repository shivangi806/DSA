//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int solve(int i,int N,int cap,int val[],int wt[],vector<vector<int>>&dp){
        if(i==N){
            if(cap==0){
                return 1;
            }
            return 0;
        }
        if(cap==0) return 0;
        if(dp[i][cap]!=-1) return dp[i][cap];
        int tk=0;
        int nt = solve(i+1,N,cap,val,wt,dp);
        if(cap-wt[i]>=0){
            tk = val[i]+solve(i,N,cap-wt[i],val,wt,dp);
        }
        return dp[i][cap] = max(tk,nt);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        long long sum=0;
        // for(int i=0;i<N;i++) sum+=val[i];
        vector<vector<int>> dp(N+1,vector<int>(W+1,-1));
        return solve(0,N,W,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends