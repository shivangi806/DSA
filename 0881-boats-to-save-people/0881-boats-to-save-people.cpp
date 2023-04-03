class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        int n= people.size();
        sort(people.begin(),people.end());
        int i=0;
        int j=n-1;
        while(i<=j){
            int sum = people[i]+people[j];
            if(sum<=limit){
                i++;
                j--;
            }
            else j--;
            ans++;
        }
        return ans ;
    }
};