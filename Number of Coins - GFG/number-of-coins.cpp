//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	
	int solve(int i , int tg , int coins[] , vector<vector<int>>&dp,int M ){
	    if(tg==0) return 0;
	    
	    if(tg!=0 && i==M-1){
	        
	        if(tg%coins[i]==0) return tg/coins[i];
	        return 1e9;
	    }
	    if(dp[i][tg]!=-1) return dp[i][tg];
	    int tk=INT_MAX;
	    if(tg-coins[i]>=0)tk = 1+solve(i,tg-coins[i],coins , dp,M);
	    
	    int nt = solve(i+1,tg,coins,dp,M);
	    
	    return dp[i][tg] = min(tk,nt);
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>> dp(M+1,vector<int>(V+1,-1));
	    
	    int ans =  solve(0,V,coins,dp,M);
	    if(ans>=1e9) return -1;
	    return ans ;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends