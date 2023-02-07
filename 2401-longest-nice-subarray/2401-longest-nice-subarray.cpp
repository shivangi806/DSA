class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=0;
        int temp =0;int ans =0;
        for(int i=0;i<n;i++){
            // if not equal to 0 then problem
            while((temp&nums[i])!=0){
                temp=temp^nums[j];
                j++;
            }
            // no problem
            // set that bit
            temp|=nums[i];
            ans= max(ans , i-j+1);
        }
        return ans ;
    }
};