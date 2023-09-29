class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0;
        int j=0;
        int czero = 0;
        int ans = 0;
        while(i<n){
            
            if(nums[i]==0){
                czero++;
            }
            
            if(czero>k){
                while(nums[j]!=0){
                    j++;
                }
                j++;
                czero--;
            }
            ans = max(ans , i-j+1);
            i++;
        }
        return ans ;
    }
};