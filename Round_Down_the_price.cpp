#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    long long int t;cin>>t;
    while(t--){
        string s;cin>>s;
        int len=s.size();
        long long int x=stoi(s);
        int power=len-1;
        double y=pow(10,power);
        long long int dif=x-(y);
        cout<<dif<<endl;
    }
    return 0;
}
