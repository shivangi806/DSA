//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int kitnasurvivekarna, int kitnamaximumonedaymeleskte, int kitnamaximumkharchkrskte){
        // code here
        int kitnesundayhai = kitnasurvivekarna/7;
        int kitnedinbache = kitnasurvivekarna-kitnesundayhai;
        
        int ans = 0;
        // phle to maximum amouunt utha lungi ab usse kitna survive karungi
        if( kitnamaximumkharchkrskte*kitnasurvivekarna % kitnamaximumonedaymeleskte ==0 ){
            ans = kitnamaximumkharchkrskte*kitnasurvivekarna / kitnamaximumonedaymeleskte;
        }
        else{
            ans = kitnamaximumkharchkrskte*kitnasurvivekarna / kitnamaximumonedaymeleskte + 1;
        }
        if(ans<=kitnedinbache) return ans ;
        return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends