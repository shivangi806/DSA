#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,sum;cin>>n>>sum;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int i,j;
    int st=0;
    int cs=a[0];
    for(int i=1;i<=n;i++){
     while(cs>sum && st<i-1){
        cs=cs-a[st];
        st++;
     }
     if(cs==sum){
     cout<<st+1<<" "<<i-1+1<<endl;
     return 0;
     }
     if(i<n){
        cs=cs+a[i];
     }

    }
    cout<<"not found"<<endl;
}