class Solution {
public:
    int atmax(vector<int>& nums, int k) {
        
        if(k<0) return 0;
        int n = nums.size();
        int ans=0,sum=0,j=0;
        int i=0;
        while(i<n){
            sum+=nums[i];
            while(sum>k){
                sum-=nums[j];
                j++;
            }
            ans += i-j+1;
            i++;
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int k) {
        return atmax(nums,k) - atmax(nums,k-1);
    }
};
