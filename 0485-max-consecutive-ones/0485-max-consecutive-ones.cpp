class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int ans=0;
        int c=0;
        while(i<n){
            while(i<n && nums[i]==1) c++,i++;
            ans = max(ans , c);
            c=0;
            i++;
        }
        return ans;
    }
};