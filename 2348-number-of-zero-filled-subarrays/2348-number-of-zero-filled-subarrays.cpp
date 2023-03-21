class Solution {
public:
    #define ll long long
    long long zeroFilledSubarray(vector<int>& nums) {
        ll sum=0 , c=0;
        for(int i =0;i<nums.size();i++){
            if(i<nums.size() && nums[i]==0 ) c++;
            else if(c != 0){
                sum +=(c*(c+1)/2);
                c=0;
            }
        } 
        sum+=(c*(c+1)/2) ;
        
        return sum;
    }
};