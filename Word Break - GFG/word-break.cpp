//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:

    bool solve(int i, string &A, vector<string> &B, int n, int m) {
    if (i == n) {
        return true; // Successfully processed the entire string
    }

    for (int k = 0; k < m; k++) {
        string s = B[k];
        int len = s.size();
        
        if (i + len <= n && A.substr(i, len) == s) {
            if (solve(i + len, A, B, n, m)) {
                return true;
            }
        }
    }
    return false;
}
    int wordBreak(string A, vector<string> &B) {
        int n = A.size();
        int m = B.size();
        return solve(0,A,B,n,m);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends