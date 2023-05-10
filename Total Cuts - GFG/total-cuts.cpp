//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        vector<int> maxi(N),mini(N);
        int count=0;
        int maxx=INT_MIN,minn=INT_MAX;
        for(int i=0;i<N-1;i++){
            maxx=max(maxx,A[i]);
                maxi[i]=maxx;
            minn=min(minn,A[N-i-1]);
            mini[N-i-1]=minn;
            }
        for(int i=0;i<N-1;i++){
            if(maxi[i]+mini[i+1]>=K)
                count++;
            }
        return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends