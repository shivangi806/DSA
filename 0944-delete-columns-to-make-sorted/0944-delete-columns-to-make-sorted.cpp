class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ans=0;
        int i=1;
        for(int j=0;j<m;j++){
            int c=0;
            for(int i=1;i<n;i++){
                if( strs[i-1][j]<=strs[i][j]){
                    c++;
                }   
            }
            if(c!=(n-1)) {
                ans++;
            }
        }
        return ans ;
    }
};

/*

strs[i][0] strs[i+1][0]





*/