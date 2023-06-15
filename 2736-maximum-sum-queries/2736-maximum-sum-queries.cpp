class Solution {
public:

    
static bool comp(vector<int>&a , vector<int>&b){
    if(a[0]==b[0]) return a[1]<b[1];
    return a[0]<b[0];
}
vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        // queries ko sort kr lete h for comparing easily
        // and uske index ko v sath rakh lenge for not any confusion
        vector<vector<int>> sq;   // sorted queries  // phle vector me daal rhe fir sort kr denge
        for(int i=0;i<queries.size();i++){
            sq.push_back({queries[i][0] , queries[i][1] , i});
        }
        sort(sq.begin(),sq.end(),comp);
        priority_queue<vector<int>> pq,tempq;
        for(int i=0;i<n;i++){
            pq.push({nums1[i]+nums2[i] , nums1[i] , nums2[i]});
        }
        vector<int> ans(queries.size() , -1);
        for(auto it : sq){
            while(!pq.empty()){
                if(pq.top()[1] <it[0]){
                    pq.pop();
                }
                else if(pq.top()[2]<it[1]){
                    tempq.push(pq.top());
                    pq.pop();
                }
                else break;
            }
            
            if(!pq.empty()){
                ans[it[2]]=pq.top()[0];
            }
            while(!tempq.empty()){
                pq.push(tempq.top());
                tempq.pop();
            }
        }
        
    
        return ans ;
    }
};