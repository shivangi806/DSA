class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0;
        int h= n-1;
        int ans1=-1 , ans2=-1;
        while(l<=h){
            int mid = (l+h)>>1;
            if(nums[mid]==target){
                ans1 = mid;
                h=mid-1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        
        l=0;
        h=n-1;
        while(l<=h){
            int mid = (l+h)>>1;
            if(nums[mid]==target){
                ans2 = mid;
                l=mid+1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return {ans1,ans2};
    }
};