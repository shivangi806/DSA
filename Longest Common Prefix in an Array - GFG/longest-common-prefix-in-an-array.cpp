//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
    string ans ;
    sort(arr,arr+N);
    string x = arr[0];
    string y = arr[N-1];
    for(int i=0;i<arr[0].size();i++){
        if(x[i]==y[i]) ans.push_back(x[i]);
        else break;
    }
    if(ans.size()==0) return "-1";
    return ans ;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends