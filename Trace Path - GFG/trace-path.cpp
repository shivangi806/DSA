//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        // code here
         int left=0,right=0,up=0,down=0;
    for(int i=0;i<s.length();i++) {
        if(s[i]=='L') { 
          left++; 
          if(right!=0) right--;
        }
        else if(s[i]=='R') {
            right++; 
            if(left!=0) left--;
        }
        else if(s[i]=='D') {
            up++; 
            if(down!=0) down--;
        }
        else if(s[i]=='U') {
            down++; 
            if(up!=0) up--;
        }
        if(left>=m || right>=m || up>=n || down>=n) return 0;
     }
     return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends