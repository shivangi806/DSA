class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       int i=0;
       int j=0;
       unordered_map<int,int> mp;
       while(i<nums.size()){
           if(mp.count(nums[i])){
               int dis = abs(i-mp[nums[i]]);
               if(dis<=k) return 1;
           }
           mp[nums[i]]=i;
           i++;
       }
        return false;
    }
};