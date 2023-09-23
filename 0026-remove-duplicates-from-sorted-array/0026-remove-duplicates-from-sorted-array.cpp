class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        int it=0;
        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i])==st.end()){
                nums[it++]=nums[i];
                st.insert(nums[i]);
            }
        }
        return st.size();
    }
};