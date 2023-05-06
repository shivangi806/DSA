//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    bool solve(int i , int K ,int target , vector<int>&coins,vector<vector<int>>&dp){
        if(target==0){
            if(K==0) return 1;
            return 0 ;
        }
        if(i==0){
            if(target/coins[i]==K && target%coins[i]==0) return 1;
            return 0;
        }
        if(dp[target][K]!=-1) return dp[target][K];
        bool take = 0;
        if(target-coins[i]>=0) take = solve(i,K-1,target-coins[i],coins,dp);
        
        bool notake = solve(i-1,K,target,coins,dp);
        return  dp[target][K]=take|notake ; 
    }
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        // code here
        vector<vector<int>> dp(target+1 , vector<int>(K+1 ,-1));
        return solve(N-1 , K , target , coins,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends