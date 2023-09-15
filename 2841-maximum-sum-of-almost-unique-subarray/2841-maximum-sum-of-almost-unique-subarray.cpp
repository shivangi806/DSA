class Solution {
public:

    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();
        vector<long long> psum(n,0);
        psum[0] = nums[0];
        for(int i = 1; i < n; i++){
            psum[i] = psum[i-1] + nums[i];
        }
        map<int,int> mp;
        long long ans = 0;
        int j = 0;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
            if(i - j + 1 == k){
                if(mp.size()>=m){
                    // means almost unique
                    ans = max(ans, psum[i] - psum[j] + nums[j]);
                }
                mp[nums[j]]--;
                if(mp[nums[j]]==0) mp.erase(nums[j]);
                j++;
            }
        }
        return ans;
    }
};
