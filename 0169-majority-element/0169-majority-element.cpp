class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c=0;
        int prevEle;
        for(int i=0;i<nums.size();i++){
            if(c==0) prevEle=nums[i];
            
            if(prevEle==nums[i]){
                c++;
            }
            else c--;
        }
        return prevEle;
    }
};