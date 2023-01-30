class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
       vector<int> arr=nums;
        sort(arr.begin(),arr.end());
        int n = nums.size();
        vector<int> idx;
        for(int i=0;i<n;i++){
            if(nums[i]!=arr[i]){
               idx.push_back(i);
            }
        }
        if(idx.size()==0) return 0;
        int len = idx.size();
        int x= idx[0];
        int y= idx[len-1];
        return abs(x-y)+1;
    }
};