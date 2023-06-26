class Solution {
public:
    int n , m;
    bool valid(char ch ,vector<vector<char>>& b , int i , int j){
        for(int k=0;k<n;k++){
            if(b[k][j]==ch) return 0;
        }
        for(int k=0;k<m;k++){
            if(b[i][k]==ch) return 0;
        }
        
        for(int k=0;k<n;k++){
            if(b[3*(i/3) + k%3][3*(j/3) + k/4] == ch) return 0;
        }
        return 1;
    }
    bool solve(vector<vector<char>>& b){
       for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b[i][j]=='.'){
                    for(char ch ='1';ch<='9';ch++){
                        if(valid(ch,b,i,j)){
                            b[i][j]=ch;
                            if(solve(b)) return 1;
                            else b[i][j]='.';
                        }
                    }
                    return 0;
                }
            }
        } 
        return 1;
    }
    void solveSudoku(vector<vector<char>>& b) {
        n = b.size();
        m = b[0].size();
        solve(b);
    }
};