class Solution {
public:
    void funct(vector<int> &nums , vector<int>&ds,set<vector<int>>&st,int idx){
        // when the iterator reaches nums size then stop it and push the ds in the set vector
        if(idx==nums.size()){
            if(ds.size()>=2){ // if the ds size is less than 2 then it should not be in our consideration so consider it only when size is greater than 1 as given in question 
            st.insert(ds);
            }
            return;
        }
        // of the ds size is 0 or when the current index value nums[idx] is greater than the previous index value ds.back() the only we will push that nums[idx] in the ds as we need only the increasing seq.
        if( ds.size()==0 || nums[idx]>=ds.back() ){
            // take the element
            ds.push_back(nums[idx]);
            funct(nums,ds,st,idx+1);  // after keeping thta element in the ds we will again call the same function with 
            // not take the element
            ds.pop_back();
            funct(nums,ds,st,idx+1);
        }
       else funct(nums,ds,st,idx+1);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> ds; // for storing the each subsequence 
        set<vector<int>> st;// for storing all subsequence which should be unique thta's why we have take set
        funct(nums,ds,st,0);
        return vector(st.begin(),st.end()) ; // return the set in form of vector as return type is vector
    }
};