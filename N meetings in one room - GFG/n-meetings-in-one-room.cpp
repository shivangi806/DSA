//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool cmp(pair<int,int>&a , pair<int,int>&b){
        if(a.second < b.second) return 1;
        return 0;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),cmp);
        int endprev = v[0].second;
        int c=1;
        for(int i=1;i<n;i++){
            int currstart = v[i].first;
            if(currstart>endprev){
                c++;
                endprev = v[i].second;
            }
        }
        return c;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends