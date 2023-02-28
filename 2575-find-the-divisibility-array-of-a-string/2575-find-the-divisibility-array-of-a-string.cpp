class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();
        vector<int> v(n);
        long long int x=0;
        for(int i=0;i<word.size();i++){
            x=x*10 + word[i]-'0' ;
            //cout<<x<<endl;
            x=x%m ;
            if(x==0) v[i]=1;
            else v[i]=0;
        }
        return v;
    }
};