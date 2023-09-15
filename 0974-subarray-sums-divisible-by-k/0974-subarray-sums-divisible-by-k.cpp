class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> psum(n,0);
        // in concept if s1%k gives remainder r and s2%k gives remainder r same
            // then s1-s2%k==0
        psum[0]=nums[0];
        for(int i=1;i<n;i++){
            psum[i]=psum[i-1]+nums[i]; // considering all subarrays sum
        }
        map<int,int> mp;
        mp[0]++;
        int ans=0;
        // sum/k = k*q + rem
        // rem is negative 
        // k*q - rem = k*(q-1) + -(rem+k) 
        for(int i=0;i<n;i++){
            int rem = psum[i]%k;
            if(rem<0){ // if rem is negative then we can write the remainder as rem+k
                // k*something-rem=0=s
                rem+=k;
            }
            ans+=mp[rem];
            mp[rem]++;
        }
        return ans ;
    }
};