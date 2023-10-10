class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return 0;
        vector<int> v;
        while(x){
            v.push_back(x%10);
            x=x/10;
        }
        vector<int> t = v;
        reverse(t.begin(),t.end());
        for(int i=0;i<v.size();i++){
            if(v[i]!=t[i]) return 0;
        }
        return 1;
    }
};