//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    #define ll long long
    long long trappingWater(int arr[], int n){
        ll ans = 0;
        vector<int> lp(n) , rp(n);
        lp[0]=0;
        rp[n-1]=0;
        for(int i=1;i<n;i++){
            lp[i]=max(lp[i-1],arr[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            rp[i]=max(rp[i+1],arr[i+1]);
        }
        for(int i=0;i<n;i++){
            int mx = min(lp[i],rp[i]);
            if(arr[i]<mx){
                ans+=(mx-arr[i]);
            }
        }
        return ans ;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends