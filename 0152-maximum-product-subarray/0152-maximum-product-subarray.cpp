class Solution {
public:
    // 
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res , prod1=1,prod2=1,ans=nums[0];
        for(int i=0;i<n;i++){
            prod1 *= nums[i];
            prod2 *= nums[n-i-1];
            res =  max(prod1  , prod2);
            ans = max(ans , res);
            if(prod1==0) prod1=1;
            if(prod2==0) prod2=1;
        }
        return ans;
    }
};