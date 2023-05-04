//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

    void solve(vector<int>&A,vector<int>&ds,int i,int sum){
        if(i>=A.size()){
            ds.push_back(sum); // at max ans me n elements honge so o(n)
            return ;
        }
        // for generating all subsets calling function 2 times for each element
        // O(2^n)
        // take 
        // ds.push_back(A[i]);
        sum+=A[i];
        solve(A,ds,i+1,sum);
        sum-=A[i];
        // ds.pop_back();
        
        // notake
        solve(A,ds,i+1,sum);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        // first sol : generate all subsets formed
        // collect it in temp vector
        // collect all those temp in vector of vector ans 
        // then sum all temp by iterating to all temp in ans 
        // vector<vector<int>> ans ;
        vector<int> ds;
        int sum =0;
        solve(arr , ds, 0,sum);
        // sorting takes O(nlogn) ;
        // sort(ans.begin(),ans.end());
        return ds ;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends