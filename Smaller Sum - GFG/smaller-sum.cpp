//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr)
    {
        // Code here
        unordered_map<long,long>map;
        vector<long long>help;
        vector<long long>sum;
        
        for(int i: arr)
        {
            help.push_back(i);
        }
        
        sort(help.begin() , help.end());
        long long dosum = 0;
        
        for(int i=0; i < help.size(); i++)
        {
           if(i == 0)
           {
               sum.push_back(0);
           }
           else
           {
               if(help[i] == help[i-1])
               {
                   
                    sum.push_back(sum[i-1]);
                    dosum += help[i-1];
               }
               else
               {
                    dosum += help[i-1];
                    sum.push_back(dosum);
               }
           }
       }

       
       for(int i = 0; i < help.size(); i++)
       {
           map[help[i]] = sum[i];
       }
       
       help.clear();
       
       for(int i= 0; i < n; i++)
       {
           help.push_back(map[arr[i]]);
       }
       return help;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends