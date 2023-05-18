//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void help(vector<vector<int>>& arr, int N, int M,int i,int j)
    {
        if(i<0||j<0||i==N||j==M||arr[i][j]==0) return;
        arr[i][j]=0;
        help(arr,N,M,i+1,j);
        help(arr,N,M,i-1,j);
        help(arr,N,M,i,j+1);
        help(arr,N,M,i,j-1);
    }

int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        int ans=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(matrix[i][j]==1)
                {
                    if(i==0||j==0||i==N-1||j==M-1)
                    {
                        help(matrix,N,M,i,j);
                    }
                }
            }
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(matrix[i][j]==1)
                {
                    ans++;
                    help(matrix,N,M,i,j);
                }
            }
        }
        return ans;    
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends