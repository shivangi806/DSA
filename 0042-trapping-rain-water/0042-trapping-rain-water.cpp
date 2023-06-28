class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> lmx(n) , rmx(n);
        lmx[0]=0;
        rmx[n-1]=0;
        for(int i=1;i<n;i++){
            lmx[i]=max(lmx[i-1] , h[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            rmx[i]=max(rmx[i+1] , h[i+1]);
        }
        int ans =0;
        for(int i=0;i<n;i++){
            int mini = min(lmx[i] , rmx[i]);
            if(mini>h[i]){
                ans+=(mini-h[i]);
            }
        }
        return ans;
    }
};