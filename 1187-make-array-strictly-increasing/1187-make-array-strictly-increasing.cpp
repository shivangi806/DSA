class Solution {
public:
    int flag =0;
    int solve(int i, int j, int prev, vector<int>& arr1, vector<int>& arr2, vector<vector<int>>& dp) {
        if (i == arr1.size())
        {
            flag =1;
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 1e9;
        if (arr1[i] > prev)
            ans = min(ans, solve(i + 1, j, arr1[i], arr1, arr2, dp));
        
        j = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        if (j < arr2.size())
            ans = min(ans, 1 + solve(i + 1, j+1, arr2[j], arr1, arr2, dp));

        return dp[i][j] = ans;
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        sort(arr2.begin(), arr2.end());
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int ans = solve(0, m, -1, arr1, arr2, dp); // Start with j = m instead of j = 0
        if(!flag) return -1;
        return ans ;
    }
};
