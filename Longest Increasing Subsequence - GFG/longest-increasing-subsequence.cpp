//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    // int solve(int i , int j , int n  , int nums[] , vector<vector<int>>&dp){
    //     if(i==n) return 0;
        
    //     if(dp[i][j+1]!=-1) return dp[i][j+1];
        
    //     int notake = solve(i+1, j , n , nums , dp);
        
    //     int take = INT_MIN;
    //     if(j==-1 || nums[i]>nums[j]){
    //         take = 1 + solve(i+1 , i , n , nums , dp);
    //     }
    //     return dp[i][j+1]= max(take , notake);
    // }
    int longestSubsequence(int n, int arr[])
    {
    //   vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    //   return solve(0,-1,n,a,dp);
         vector<int> ds;
         ds.push_back(arr[0]);
         for(int i=1;i<n;i++){
             if(arr[i]>ds.back()){
                 ds.push_back(arr[i]);
             }
             else{
                 int idx = lower_bound(ds.begin(),ds.end(),arr[i])-ds.begin();
                 ds[idx]=arr[i];
             }
         }
         return ds.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends