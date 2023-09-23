class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int c=0;
        int ans=0;
        for(int i=0;i<n;i++){
            c=0;
            while(i<n && nums[i]==1){
                c++;
                i++;
            }
            ans = max(ans , c);
        }
        return ans;
    }
};