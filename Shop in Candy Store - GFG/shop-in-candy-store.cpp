//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int cost[], int n, int k)
    {
        // choose the candy with high 
        sort(cost,cost+n);
        int l =0;
        int h= n-1;
        int ans1 =0;
        while(l<=h){
            ans1+=cost[l];
            l++;
            h-=k;
        }
        reverse(cost,cost+n);
        l=0;
        h=n-1;
        int ans2=0;
        while(l<=h){
            ans2+=cost[l];
            l++;
            h-=k;
        }
        return {ans1,ans2};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends