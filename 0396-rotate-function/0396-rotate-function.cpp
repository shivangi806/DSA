class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int  k = n-1 ; // number of times an array will be rotated
        int sum = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans += i*nums[i];
        }
        int comefirstindex = n-1 ;
        int ret = ans ;
        for(int i=0;i<k;i++){
            ans = ans + ( sum - (n-1)*nums[comefirstindex] - nums[comefirstindex]);
            ret = max(ret , ans);
            comefirstindex--;
        }
        return ret ;
    }
};