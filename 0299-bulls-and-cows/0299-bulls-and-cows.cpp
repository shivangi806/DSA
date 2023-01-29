class Solution {
public:
    string getHint(string s, string g) {
       int n = s.size();
        int x=0;
        string gh=s;
       map<char,int> m1,m2;
       for(int i=0;i<n;i++){
           if(s[i]==g[i]){
               x++;
           }
           else{
               m1[s[i]]++;
               m2[g[i]]++;
           }
       }
        int y=0;
    for(auto it : m1){
        if(m2.find(it.first)!=m2.end()){
            y+=min(m2[it.first],it.second);
        }
    }
     string ans ;
     ans=to_string(x)+"A"+to_string(y)+"B";
        return ans;
    }
};