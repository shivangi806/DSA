class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ans=0;
        for(int j=0;j<m;j++){
            int c=0;
            int i=1;
            while(i<n){
                if(strs[i-1][j]<=strs[i][j]){
                    c++;
                    cout<<'i'<<i;
                }   
                i++;
            }
            if(c!=(n-1)) {
                ans++;
                cout<<j;
            }
        }
        return ans ;
    }
};

/*

strs[i][0] strs[i+1][0]





*/