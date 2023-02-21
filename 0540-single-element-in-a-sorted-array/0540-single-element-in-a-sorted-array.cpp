class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        if(h==0){
            return nums[l];
        }
        if(nums[0]!=nums[1]){
          return nums[0];
        }
        if(nums[h]!=nums[h-1]){
            return nums[h];
        }
        while(l<h){
            int m=(l+h)/2 ;
            if(nums[m]!=nums[m+1]  && nums[m]!=nums[m-1]) return nums[m];
            // if got even mid index then for pair check for mid+1 index(odd)
            // if mid(even index) and mid+1(odd index) values will be equal then we will search in right part of mid
            // if mid(odd index) and mid-1(even index) values will be equal then also ignore the left part
            // ignore by increment the low to m+1
            if(m%2==0 && nums[m]==nums[m+1] || m%2!=0 && nums[m]==nums[m-1]) l=m+1;
            // else ignore the right part by decrement the h value  by m-1
            else h=m-1;
        }
        return nums[l];
    }
};