//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool pal(int i , int j , string &s){
        while(i<j){
            if(s[i]!=s[j]) return 0;
            else{
                i++;
                j--;
            }
        }
        return 1;
    }
    int n;
    int solve(int i ,string &s ,vector<int>&dp){
        if(i>=s.size()-1) return 0;
        if(pal(i,n-1,s)) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = INT_MAX;
        for(int k=i;k<s.size();k++){
            if(pal(i,k,s)){
                int temp = 1 + solve(k+1,s,dp);
                ans = min(ans , temp);
            }
        }
        return dp[i] = ans ;
    }
    int palindromicPartition(string str)
    {
        n = str.size();
        vector<int> dp(n+1,-1);
        return solve(0,str,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends