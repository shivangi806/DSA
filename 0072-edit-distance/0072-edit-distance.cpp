class Solution {
public:
    
int mini(string word1, string word2,int i , int j ,vector<vector<int>>&dp){
        if(j<0) return i+1;
        if(i<0) return j+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return mini(word1,word2,i-1,j-1,dp);
        return dp[i][j]=1+min(mini(word1,word2,i-1,j,dp),min(mini(word1,word2,i,j-1,dp),mini(word1,word2,i-1,j-1,dp)));
        
    }
    int minDistance(string word1, string word2) {
        // insert
        // delete
        // replace
        int n = word1.size(),m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return mini(word1,word2,n-1,m-1 , dp);
    }
};