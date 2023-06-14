//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		


    vector<vector<int>> dp;
    private:
    int solve(int i , int pi ,int n, int nums[]){
        if(i>=n) return 0;
        
        if(dp[i][pi+1]!=-1) return dp[i][pi+1];
        
        int no = solve(i+1 , pi , n , nums);
        int yes = INT_MIN;
        if(pi==-1 || nums[i]>nums[pi]){
            yes = nums[i] + solve(i+1 , i ,n , nums);
        }
        return dp[i][pi+1]=max(no , yes);
    }
	public:
	int maxSumIS(int arr[], int n)  
	{  
        dp.resize(n,vector<int>(n+1 , -1));
        return solve(0,-1,n,arr);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends