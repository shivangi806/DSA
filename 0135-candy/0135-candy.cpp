class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        // for  only candies[i-1] and candies[i] check
        vector<int> candies(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i-1]<ratings[i]){
                candies[i]=candies[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                candies[i]=max(candies[i+1]+1 , candies[i]);
            }
        }
        int ans =0;
        for(auto it : candies) ans+=it;
        return ans ;
    }
};