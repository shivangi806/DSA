class Solution {
public:
    
    int n,m;
    bool dfs(vector<vector<char>>& board,string &word , int k , int i , int j){
        if(k==word.size()) return 1;
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=word[k]) return 0;
        
        char s = board[i][j];
        board[i][j]='@';
        if(dfs(board,word,k+1,i+1,j)) return 1;
        if(dfs(board,word,k+1,i,j+1)) return 1;
        if(dfs(board,word,k+1,i-1,j)) return 1;
        if(dfs(board,word,k+1,i,j-1)) return 1;
        
        board[i][j]=s;
        return 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j]){
                    bool f = dfs(board,word,0,i,j);
                    if(f==1) return 1;
                }
            }
        }
        return 0;
    }
};