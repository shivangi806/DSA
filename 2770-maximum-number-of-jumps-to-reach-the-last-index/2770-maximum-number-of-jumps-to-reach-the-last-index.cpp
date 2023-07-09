class Solution {
public:
    int maxjump(vector<int>&nums ,int i,int j,int target,vector<vector<int>>&dp)
    { 
        if(i==nums.size()-1)
        { 
            if(-target <= nums[i]-nums[j] && nums [i]-nums[j]<=target)
            return 1; 
            else return -1;
        }
        if(dp[i][j]!=-24) return dp[i][j];
        
        int notake = maxjump(nums,i+1,j,target,dp);
        
        int take =INT_MIN;
        if(-target<=nums[i]-nums[j] && nums[i]-nums[j]<=target)
        {    
             int x=maxjump(nums,i+1,i,target,dp);
             if(x==-1) take=-1 ;

             else take=1+x;
        }
        return dp[i][j]=max(take,notake);
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,-24));
        int ans=maxjump(nums,1,0, target,dp); 
        if(ans==0) return -1;
        return ans ;
    }
};