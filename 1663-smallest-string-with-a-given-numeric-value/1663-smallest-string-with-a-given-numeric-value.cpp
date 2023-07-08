class Solution {
public:
    string getSmallestString(int n, int k) {
       int c=0;
       string s;
       for(int i=0;i<n;i++){
           s+='a';
       }
       k=k-n;
       if(k==0){
           return s;
       }
       for(int i=n-1;i>=0;i--){
           if(k==0){
               return s;
           }
           else if(k<=25){
               // if k < =25 means any one char is needed from a to z only for that index
               // and after that no need just return 
               s[i]=(char)('a'+k);
               k=0;
           }
           else{
               // if the value of k>25 means z will be kept but also we need more char for reching this k value 
               s[i]=(char)('a'+25);
               k=k-25;
           }
       }
        return s;
    }
};