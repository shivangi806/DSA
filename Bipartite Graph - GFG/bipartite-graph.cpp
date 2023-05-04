//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
// it can be connected graph or not connected graph


    bool check(int i , int V , vector<int>adj[],int color[]){
        queue<int> q;
	    q.push(i);
	    color[i]=1;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        for(auto it : adj[node]){
	            
	            if(color[it]==-1){
	              q.push(it);
	              color[it]=!color[node];
	            }
	            else{
	                if(color[it]==color[node]) return 0;
	            }
	        }
	    }
	    return 1;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    for(int i=0;i<V;i++) color[i]=-1;
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(!check(i,V,adj,color)) return 0;
	        }
	    }
	    return 1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends