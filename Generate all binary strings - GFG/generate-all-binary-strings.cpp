//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void solve(int i , int len , string s){
        if(i==len){
            cout<<s<<" ";
            return ;
        }
        
        // 1st call to include 0 
        solve(i+1 , len , s+'0');
        
        // 2nd call to include 1 but only if it's previous is not 1
        if(s[i-1]!='1') solve(i+1  , len , s+'1');
    }
    void generateBinaryStrings(int num){
        //Write your code
        string s ;
        solve(0,num , s);
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends