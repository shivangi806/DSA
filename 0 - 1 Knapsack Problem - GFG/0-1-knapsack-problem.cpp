//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    
    public:
    vector<vector<int>> dp;
    
    int solve(int j , int arr[] , int val[] , int i){
        if(i==0 || j==0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        
        int notake = solve(j,arr,val,i-1);
        int take = INT_MIN ;
        if(j-arr[i-1] >=0){
            take = val[i-1] + solve(j-arr[i-1],arr , val , i-1);
        }
        
        return dp[i][j] =  max(take , notake);
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       dp.resize(n+1 , vector<int>(W+1 , -1));
       return solve(W,wt,val,n);
       
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends