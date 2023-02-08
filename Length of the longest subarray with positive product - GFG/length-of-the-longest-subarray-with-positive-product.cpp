//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           int ans =0;
           int ngvCount =0 ,ngvIdx =-1,zeroIdx=-1;
           for(int i=0;i<n;i++){
               if(arr[i] < 0){
                   ngvCount+=1;
                   if(ngvIdx==-1){
                       ngvIdx=i;
                   }
               }
               if(arr[i]==0){
                   zeroIdx =i;
                   ngvIdx=-1;
                   ngvCount=0;
               }
               else{
                   if(ngvCount%2==0){
                       ans = max(ans , i-zeroIdx);
                   }
                   else{
                       ans = max(ans , i-ngvIdx);
                   }
               }
           }
           return ans ;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends