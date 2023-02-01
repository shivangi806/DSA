class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum =0;
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i] ;
            ans += i*nums[i];
        }
        int res=ans ;
        int idx = n-1;
        for(int k=1 ;k <n  ;k++){
            ans = ans   +  sum - nums[idx]*(n-1) - nums[idx] ;
            res = max(res , ans) ;
            idx--;
        }
        return res;
    }
};
