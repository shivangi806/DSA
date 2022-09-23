#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;cin>>t;
    while(t--){
    int x;cin>>x;
    vector<int> v;
    int n=x;
    if(x>45){
        cout<<"-1"<<endl;
    }
    else if(x<9){
        cout<<x<<endl;
    }
    else{
    for(int i=9;i>0;i--){
    if(n>=i){
        v.push_back(i);
        n=n-i;
    }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }
    cout<<endl;
    }
    }
}
