//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    // your code here
    int op =0;
    int cl=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='{'){
            op++;
        }
        else{
            if(op!=0){
                op--;
            }
            else{
                cl++;
            }
        }
    }
    if((op+cl)%2!=0) return -1;
    return op/2 + op%2 + cl/2 + cl%2;
}