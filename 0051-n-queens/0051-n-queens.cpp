class Solution {
public:
    vector<vector<string>> ans;
    bool isValid(int n ,char **input, int row, int col){
        
        for(int i=row;i>=0;i--){
                if(input[i][col] == 'Q')return false;
            }
        
        for(int i=row,j=col;i>=0 and j>=0;i--,j--){
            if(input[i][j] == 'Q')return false;
        }
        
        for(int i=row,j=col;i>=0 and j<n; i--,j++){
            if(input[i][j] == 'Q')return false;
        }
        return true;
    }
    
    void queen(int n, char **input,int i, int j){
        if(i>=n){
            vector<string> res;
            for(int l=0;l<n;l++){
                string s;
                for(int k=0;k<n;k++){
                    s+=input[l][k];
                }
                res.push_back(s);
            }
            ans.push_back(res);
            return;
        }
        for(int j=0;j<n;j++){
            if(isValid(n,input,i,j)){
                input[i][j]='Q';
                queen(n,input,i+1,0);
                input[i][j]='.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n==0)return {{}};
        // z=n;
        char **input = new char*[n];
        
        for(int i=0;i<n;i++){
            input[i] = new char[n];
            for(int j=0;j<n;j++){
                input[i][j] = '.';
            }
        }
        
        queen(n,input,0,0);
        return ans;
    }
};