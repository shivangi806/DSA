//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        // code here
        vector<char> v ;
        int n = s.size();
        int l=0 , h = n-1;
        while(l<=h){
            if(s[l]!=s[h]){
                if(s[l]=='?'){
                    s[l]=s[h];
                }
                else if(s[h]=='?'){
                    s[h]=s[l];
                }
                else return -1 ;
            }
            l++;
            h--;
        }
        for(int i=0;i<n;i++){
            if(s[i]!='?') {
                v.push_back(s[i]);
                // cout<<s[i];
            }
        }
    
        if(v.size()<=1) return 0;
        int sum =0;
        for(int i=1;i<v.size();i++){
            sum+=abs(v[i]-v[i-1]);
        }
        return sum ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends