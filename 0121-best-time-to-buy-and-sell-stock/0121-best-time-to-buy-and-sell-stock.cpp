class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 0 se ith tk me se minimum element nikal rhe and usse minus karke profit nikal rhe
        int mini_ab_tk = prices[0];
        int ans = INT_MIN ;
        for(int i=0;i<prices.size();i++){
            mini_ab_tk = min(mini_ab_tk , prices[i]);
            int profit = prices[i]-mini_ab_tk;
            ans = max(ans , profit);
        }
        return ans ;
    }
};