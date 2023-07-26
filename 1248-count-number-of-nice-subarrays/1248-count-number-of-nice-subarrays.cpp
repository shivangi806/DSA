class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        int i=0;
        int c=0;
        int ans = 0;
        unordered_map<int,int> mp;
        while(i<n){
            if(nums[i]%2) c++;
            if(c==k){
                ans++;
            }
            if(mp.find(c-k)!=mp.end()){
                ans+=mp[c-k];
            }
            mp[c]++;
            i++;
        }
        return ans ;
    }
};