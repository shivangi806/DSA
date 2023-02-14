class Solution {
public:
    string addBinary(string a, string b) {
       int alen = a.size();
       int blen = b.size();
       string s ;
       if(alen>blen) b=s.append(alen-blen , '0')+b;
       else if(alen<blen) a=s.append(blen-alen,'0')+a;
        int carry =0;
        string res;
       for(int i=a.size()-1;i>=0;i--){
           int sum =(a[i]-'0')+(b[i]-'0')+carry;
           res=to_string(sum%2)+res;
           carry=sum/2;
       }
       if(carry!=0) res = "1"+res;
       return res ;
    }
};