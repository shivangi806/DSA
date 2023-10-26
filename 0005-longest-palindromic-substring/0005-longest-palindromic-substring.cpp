class Solution {
public:
    
    int len(int i, int j , string &s){
        while(i>=0 && j<s.size() &&  s[i]==s[j]){
            i--;
            j++;
        }
        return j-i-1;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen=0;
        int st=0;
        for(int i=0;i<n;i++){
            
            int l1 = len(i,i,s); // even length
            int l2 = len(i,i+1,s); // odd length
            
            int temp = max(l1,l2);
            if(maxlen<temp){
                maxlen=temp;
                st = i-(maxlen-1)/2;
            }
        }
        return s.substr(st,maxlen);
    }
};