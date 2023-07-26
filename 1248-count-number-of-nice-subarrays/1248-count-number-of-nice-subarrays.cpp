class Solution {
public:
    
    int atmost(vector<int>&nums , int k){
        int c=0;
        int i=0;
        int j=0;
        int  n = nums.size();
        int ans =0;
        while(i<n){
            
            if(nums[i]%2!=0) c++;
            while(c>k){
                if(nums[j]%2!=0){
                    c--;
                }
                j++;
            }
            ans+=(i-j+1);
            i++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};