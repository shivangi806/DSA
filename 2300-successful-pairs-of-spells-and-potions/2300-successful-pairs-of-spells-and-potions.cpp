
class Solution {
public:

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
    {
        int n = spells.size();
        vector<int>ans(n);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++){
            int m = potions.size();
            int index =m;
            int l=0,h=m-1;
            while(l<=h){
                long long mid = l + (h-l)/2 ;
                long long prod = (long long )spells[i] * (long long )potions[mid] ;
                if(prod>=success){
                    index = mid;
                    h=mid-1;
                }
                else l= mid+1 ;
            }
            ans[i] = m-index ;  
        } 
         return ans ;   
    }
};