//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	#define ll long long
    void solve(int i , int sum , vector<int>&nums , set<int>&st ,vector<vector<int>>&dp){
        if(i>=nums.size()){
            st.insert(sum);
            return ;
        }
        
        if(dp[i][sum]!=-1) return;
        solve(i+1,sum+nums[i],nums , st,dp);
        solve(i+1,sum,nums,st,dp);
        
        dp[i][sum]=0;
        
    }
	vector<int> DistinctSum(vector<int>nums){
	    int n = nums.size();
	    
	    ll sum=0;
	    for(int i=0;i<nums.size();i++) sum+=nums[i];
	    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
	    set<int> st;
	    solve(0,0,nums,st,dp);
	    vector<int> ans  (st.begin(),st.end());
	    return ans ;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int> ans = obj.DistinctSum(nums);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}

// } Driver Code Ends