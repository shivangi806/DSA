class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> rowmin;
        vector<int> colmax;
        
        for(int i=0;i<n;i++){
            int mini=INT_MAX;
            for(int j=0;j<m;j++){
                mini = min(mini,matrix[i][j]);
            }
            rowmin.push_back(mini);
        }
        for(int i=0;i<m;i++){
            int maxi=INT_MIN;
            for(int j=0;j<n;j++){
                maxi = max(maxi,matrix[j][i]);
            }
            colmax.push_back(maxi);
        }
        vector<int> ans ;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==rowmin[i] && matrix[i][j]==colmax[j]){
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans ;
    }
};