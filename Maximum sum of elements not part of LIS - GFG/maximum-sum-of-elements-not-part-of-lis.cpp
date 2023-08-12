//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxSumLis(int Arr[], int n) {
        vector<int> lis;
        int sum=0,lisSum[n+1]; //lisSum[i] -> stores sum of lis of length i
        lisSum[0]=0;
        for(int i=0;i<n;i++){
            sum+=Arr[i];
            int index = lower_bound(lis.begin(),lis.end(),Arr[i])-lis.begin();
            if(index==lis.size())
                lis.push_back(Arr[i]);
            else lis[index]= Arr[i];
            lisSum[index+1]=lisSum[index]+Arr[i];
        }
        return sum-lisSum[lis.size()];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int Arr[n];
        for (int i = 0; i < n; i++) cin >> Arr[i];
        Solution obj;
        cout << obj.maxSumLis(Arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends