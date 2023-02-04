class Solution {
public:
    bool all_zero(int fq[]){
        for(int i=0;i<26;i++){
            if(fq[i]!=0){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int fq[26]={0};
        int k = s1.size(); // window size
        for(int i=0;i<s1.size();i++){
            fq[s1[i]-'a']++;
        }
        for(int i=0;i<s2.size();i++){
            fq[s2[i]-'a']--;
            if(i - k >=0){ // found the window size
               fq[s2[i-k]-'a']++; // remove the i-k th char by increasing it's count for sliding the window
            }
            if(all_zero(fq)) return true; 
        }
      return false;
    }
};