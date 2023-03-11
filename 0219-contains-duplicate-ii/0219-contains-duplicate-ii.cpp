class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int j=0;j<n;j++){
            if(mp.count(nums[j])){
                if( ( j-mp[nums[j]]) <= k  ) return 1;
            }
            mp[nums[j]] = j;
        }
        return 0;
    }
};