class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int it=0;int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[it++]=nums[i];
            }
            if(nums[i]==0) c++;
        }
        for(int i=0;i<c;i++) nums[it++]=0;
    }
};