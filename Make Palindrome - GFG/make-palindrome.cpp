//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
        unordered_map<string , int>  mp;
        for(auto it : arr){
            string x = it;
            reverse(x.begin(),x.end());
            if(mp.find(x)!=mp.end()){
                mp.erase(x);
            }
            else{
                mp[it]=1;
            }
        }
        if(mp.size()==0) return 1;
        if(mp.size()==1){
            for(auto it : mp){
                string x = it.first;
                string y = x;
                reverse(y.begin(),y.end());
                if(x==y) return 1;
                else return 0;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends