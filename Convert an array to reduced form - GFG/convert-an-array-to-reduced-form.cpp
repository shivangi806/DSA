//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Converts arr[0..n-1] to reduced form.
	void convert(int arr[], int n) {
	    // code here
	    map<int,int> m;
	    for(int i=0;i<n;i++){
	        m[arr[i]]=i;
	    }
	    //sort(m.begin(),m.end());
	    int c=0;
	   // for(auto it : m){
	   //     arr[c++]=it.second;
	   // }
	    for(auto it : m){
	        arr[it.second]=c;
	       // cout<<it.second<<endl;
	    c++;
	    }
	    return ;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.convert(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends