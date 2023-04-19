//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        for(int i=0;i<N;i++){
            if(S[i]=='1'){
                int j=i-1;
                int k=i+1;
                int t=X;
                while(t--){
                    if(j>=0 && S[j]!='1') S[j]='2';
                    if(k<N && S[k]!='1') S[k]='2';
                    j--;
                    k++;
                }
            }
        }
        
        for(int i=0;i<N;i++){
           
            if(S[i]=='0') return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends