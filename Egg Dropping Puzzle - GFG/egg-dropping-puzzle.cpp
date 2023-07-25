//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int egg , int flr,vector<vector<int>>&dp){
        if(egg==0 || egg==1) return flr;
        if(flr==0 || flr==1) return flr;
            
        if(dp[egg][flr]!=-1) return dp[egg][flr];
        int ans = INT_MAX;
        for(int k=1;k<=flr;k++){
            int temp =1+ max(solve(egg-1,k-1,dp) , solve(egg,flr-k,dp));
            ans = min(ans , temp);
        }
        
        return dp[egg][flr]=ans ;
    }
    int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(n,k,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends