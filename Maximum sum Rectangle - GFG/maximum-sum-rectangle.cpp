//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int kadanes(vector<int>&arr){
        int sum=0;
        int ans = INT_MIN;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            ans = max(ans,sum);
            if(sum<0){
                sum=0;
            }
        }
        return ans ;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        int ans = INT_MIN;
        for(int cstart=0;cstart<C;cstart++){
            vector<int> col(R,0);
            for(int cend=cstart;cend<C;cend++){
                for(int i=0;i<R;i++){
                    col[i]+=M[i][cend];
                }
                ans = max(ans , kadanes(col));
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends