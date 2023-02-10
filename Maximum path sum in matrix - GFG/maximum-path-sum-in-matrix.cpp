//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // bool valid(int i , int j , vector<vector<int>> &m){
    //     int n = m.size();
    //     if(i>=0 && j>=0 && i<n && j<n){
    //         return 1;
    //     }
    //     return 0;
    // }
    // bool isThrees(int i , int j , vector<vector<int>>&m){
    //     int n = m.size();
    //     if(valid(i+1,j,m)) return 1;
    //     if(valid(i+1,j-1,m)) return 1;
    //     if(valid(i+1,j+1,m)) return 1;
    //     return 0;
    // }
    int dp[501][501] ;
    int solve(int n , vector<vector<int>>&m , int i , int j){
        if(j<0 || j> n-1) return -1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==n-1) return m[i][j];
        int x = solve(n,m,i+1,j);
        int y = solve(n,m,i+1,j+1);
        int z = solve(n,m,i+1,j-1);
        
        return dp[i][j] = m[i][j] + max({solve(n,m,i+1,j) , solve(n,m,i+1,j+1) , solve(n,m,i+1,j-1)}) ;
        
    }
    int maximumPath(int n, vector<vector<int>> Matrix)
    {
        // code here
        // array is , my rows starting from row 0
        // we need maximum cost picking any one element out of 3
        // first find the recursive approach 
        // base condition
        int ans=0 ;
        memset(dp,-1,sizeof(dp));
        for(int c=0;c<n;c++){
            ans = max(ans , solve(n,Matrix,0,c));
        }
        return ans ;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends