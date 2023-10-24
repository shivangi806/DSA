class Solution {
public:
    vector<vector<int>> ans;
    void sol(vector<int> &ds,vector<int>& arr, int tg,int i){
        if(i==arr.size()){
            // no element
            if(tg==0){
                ans.push_back(ds);
            }
            return ;
        }
        
        if(tg==0){
             ans.push_back(ds);
            return;
        }
        
//         if(tg-arr[i]>=0){
//             ds.push_back(arr[i]);
//             sol(ds,arr,tg-arr[i],i+1);
//             ds.pop_back();
//         }
        
//          sol(ds,arr,tg,i+1);
        
        // as here we were using 2 ways for each element taking long time
        // no will be using a loop only , just summing while going when exceed will break
        
        for(int k=i;k<arr.size();k++){
            if(arr[k]>tg) break;
            
            if(k>i && arr[k]==arr[k-1]){
                continue;
            }
            ds.push_back(arr[k]);
            sol(ds,arr,tg-arr[k],k+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int tg) {
        sort(arr.begin(),arr.end());
        vector<int> ds;
        sol(ds,arr,tg,0);
        return ans;
    }
};