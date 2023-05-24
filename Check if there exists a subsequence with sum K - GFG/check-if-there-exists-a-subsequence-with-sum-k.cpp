//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    
    bool f(int i, vector<int>& arr, int tg, int n, int dp[][1001]) {
    if (tg == 0) return true;
    if (i == n) return false;
    if (dp[i][tg] != -1) return dp[i][tg];
    bool l = false;
    bool r = false;
    if (tg - arr[i] >= 0) {
        l = f(i + 1, arr, tg - arr[i], n, dp);
    }
    r = f(i + 1, arr, tg, n, dp);
    return dp[i][tg] = l || r;
}

bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
    int dp[n + 1][1001];
    memset(dp, -1, sizeof(dp));
    return f(0, arr, k, n, dp);
}

};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    }
    return 0;
}
// } Driver Code Ends