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

    int solve(int i , int n , int m , string &A , vector<string>&B){
        if(i>=n) return 1;
        string ds;
        for(int k=0;k<m;k++){
            ds=B[k];
            int len =ds.size();
            if(i+len<=n && A.substr(i,len)==ds){
                if(solve(i+len,n,m,A,B)) return 1;
            }
        }
        return 0;
    }
    int wordBreak(string A, vector<string> &B) {
        int n = A.size();
        int  m = B.size();
        return solve(0,n,m,A,B);
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