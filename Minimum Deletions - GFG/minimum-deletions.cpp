//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    int solve(int i , int j, string &s , string &t , vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==t[j]){
            return dp[i][j] = 1 + solve(i-1,j-1,s,t,dp);
        }
        else{
            return dp[i][j] = max(solve(i-1,j,s,t,dp) , solve(i,j-1,s,t,dp));
        }
        return dp[i][j];
    }
    
    int minimumNumberOfDeletions(string s) { 
        // code here
        int n = s.size();
        string   t = s;
        reverse(t.begin(),t.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int temp = solve(n-1,n-1,s,t,dp);
        return n-temp;
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends