class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> psum(n+1,0) , ssum(n+1,0);
        for(int i =0 ; i<n-1 ;i++){
            psum[i+1] =psum[i] + nums[i];
        }
        ssum[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            ssum[i] = ssum[i+1]+nums[i];
        }
        
        reverse(ssum.begin(),ssum.end());
        int ans = 0;
        for(int i=0;i<=k;i++){
           ans = max(ans , psum[i]+ssum[k-i]) ;
        }
        return ans;
    }
};