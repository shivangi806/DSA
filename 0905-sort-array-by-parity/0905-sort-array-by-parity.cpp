class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int k=0;
        int l=n-1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                ans[k]=nums[i];
                k++;
            }
            else if(nums[i]%2!=0){
                ans[l]=nums[i];
                l--;
            }
            
        }
        return ans ;
    }
};