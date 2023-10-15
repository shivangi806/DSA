class Solution {
public:
    #define dd double
    double findMaxAverage(vector<int>& nums, int k) {
        // maximum sum of length k
        dd sum=0;
        int i=0;
        int j=0;
        dd ans=INT_MIN;
        
        while(i<nums.size()){
            sum+=nums[i];
            if(i-j+1==k){
                ans=max(ans,sum/k);
                sum-=nums[j];
                j++;
            }
            i++;
        }
        return ans;
    }
};