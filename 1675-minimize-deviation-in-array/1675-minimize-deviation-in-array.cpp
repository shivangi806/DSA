class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return INT_MAX ;
        priority_queue<int> veven;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                veven.push(nums[i]);
                mini = min(nums[i] , mini);
            }
            else{
                veven.push(nums[i]*2);
                mini = min(nums[i]*2 , mini);
            }
        }
        int res = INT_MAX ;
        while(veven.top()%2==0){
            int max = veven.top();
            veven.pop();
            res = min(res,max-mini);
            int newnum = max/2;
            veven.push(newnum);
            mini=min(mini,newnum);
        }
        res = min(veven.top()-mini , res);
        return res;
    }
};