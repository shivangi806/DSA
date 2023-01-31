class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g =0;
        int n = nums.size();
        int m = numsDivide.size();
        for(int i=0;i<m;i++){
             g = __gcd(g,numsDivide[i]);
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(g % nums[i]==0) return i;
        }
        return -1;
    }
};