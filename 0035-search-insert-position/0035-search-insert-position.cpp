class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int h=nums.size()-1;
        int mid;
        while(l<=h){
            mid=(l+h)/2;
            if(nums[mid]==target){
               return mid;
            }
            else if(nums[mid] > target){
                h=mid-1;
            }
            else if(nums[mid] < target){
                l=mid+1;
            }
        }
        return l;
    }
};