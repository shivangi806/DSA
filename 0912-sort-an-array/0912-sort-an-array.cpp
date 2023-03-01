class Solution {
public:
    vector<int> sortArray(vector<int>& nums){
     multiset<int> st;
     for(int i=0;i<nums.size();i++){
         st.insert(nums[i]);
     }
    vector<int> v;
    for(auto x : st){
        v.push_back(x);
    }
    return v;
    }
};