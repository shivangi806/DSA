class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmax(n,0) , rmax(n,0);
        for(int i=1;i<n;i++){
            lmax[i]=max(lmax[i-1],height[i-1]);
        }
        
        for(int i=n-2;i>=0;i--){
            rmax[i]=max(rmax[i+1],height[i+1]);
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            int mini = min(lmax[i],rmax[i]);
            if(height[i]<mini){
                ans += abs(height[i]-mini);
            }
        }
        return ans;
    }
};