#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        string s;
        cin>>s;
        int flag=1;
        for(int i=0;i<s.size();i++){
           int ca=1;
           while(s[i]==s[i+1] && (i+1)<s.size()){
           ca++;
            i++;
           }
           if(ca<2){
            flag=0;
            break;
           }
        }
        if(flag==0){
            cout<<"NO"<<endl;
        }
        else if(flag==1){
            cout<<"YES"<<endl;
        }
        
    }
}