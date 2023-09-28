class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int k=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                ans[k]=nums[i];
                k++;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0){
                ans[k]=nums[i];
                k++;
            }
        }
        return ans ;
    }
};