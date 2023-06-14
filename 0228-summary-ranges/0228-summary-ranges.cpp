class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        string temp;
        vector<string> ans ;
        for(int i=0;i<n;i++){
            
            int c=0;
            // i=0;
            // 1 = 0+1 
            // c=1
            // i=1
            // 2 = 1 + 1
            // c=2
            // i=2
            int x =i;
                while(i+1<n && nums[i+1]==nums[i]+1){
                    c++;
                    i++;
                }
            // c=2 > 0
            if(c>0){
                temp+=to_string(nums[x]);
                temp+="->";
                temp+=to_string(nums[x+c]);
            }
            else{
                temp+=to_string(nums[i]);
            }
            ans.push_back(temp);
            temp="";
        }
        return ans ;
    }
};