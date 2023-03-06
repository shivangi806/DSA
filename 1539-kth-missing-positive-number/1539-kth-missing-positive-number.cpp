class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int last=arr.size();
        int n = arr[last-1];
        unordered_map<int,int> mp;
        for(int i=0;i<last;i++) mp[arr[i]]++;
        vector<int> v;
        for(int i=1;i<=n;i++){
            if(mp[i]<1){
                v.push_back(i);
            }
        }
        if(v.size()<k){
            for(int i=1;i<=k;i++){
                v.push_back(n+i);
            }
        }
        return v[k-1] ;
    }
};