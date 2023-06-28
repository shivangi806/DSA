class Solution {
public:
    vector<long long int>dp;
    bool isPalin(string &t){
        int i = 0;
        int j = t.size()-1;
        while(i<j){
            if(t[i]!=t[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int fun(int idx,int n,string &s){
        if(idx==s.size()-1){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        long long maxi = 1e9;
        string t = s.substr(idx);
        if(isPalin(t)) return 0;
        for(int i=idx;i<s.size();i++){
            string t = s.substr(idx,i-idx+1);
            if(isPalin(t)){
                long long tmp =  1+fun(i+1,n,s);
                maxi = min(maxi,tmp);
            }
        }
        return dp[idx] = (int)maxi;
    }
    int minCut(string s) {
        if(isPalin(s)){
            return 0;
        }
        int n = s.size();
        string tt = s.substr(0,n-1);
        if(isPalin(tt) && isPalin(s)){
            return 0;
        }
        if(isPalin(tt) && !isPalin(s)){
            return 1;
        }
        
        dp.resize(n+1,-1);
        int ans = fun(0,n,s);
        return ans;
    }
};