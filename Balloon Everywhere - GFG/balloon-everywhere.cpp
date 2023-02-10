//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        int b = m['b'];
        int a = m['a'];
        int l = m['l']/2;
        int o = m['o']/2;
        int n=  m['n'];
        int mini = min({b,a,l,o,n});
        return mini ;
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends