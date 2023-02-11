class Solution {
public:
    int mod = (int)(1e9+7);
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> v;
        // powers of 2 ko collect karung jb tk vo less tha equal to n h
        for(int i=0;i<32;i++){
            if(n&(1<<i)){   // if it is set at various pos of bit representation of n
                v.push_back(1<<i);  // push that 2 to the power in v
            }
        }
        // ab hmare paas sare powers aa gye hai
        // vector<int> pmul(v.size());
        // pmul[0]=v[0];
        // for(int i=1;i<=v.size();i++){
        //     pmul[i]=pmul[i-1]*v[i] ;
        // }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int a = queries[i][0];
            int b = queries[i][1];
            long long temp =1;
            for(int j=a;j<=b;j++){
                temp=((temp%mod)*v[j])%mod;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};