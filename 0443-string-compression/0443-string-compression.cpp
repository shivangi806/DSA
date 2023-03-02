class Solution {
public:
    int compress(vector<char>& v){
        
     int n = v.size();
     int i=0,j=0;
     int c=1;
        if(n==1){
            return 1;
        }
     for(int i=0;i<n-1;i++){
         if(v[i]==v[i+1]){
             c++;
         }
         else{
             v[j]=v[i];
             j++;
             if(c>1){
                 string str = to_string(c);
                 for(int i=0;i<str.size();i++){
                     v[j++]=str[i];
                 }
                 c=1;
             }
         }
     }
        if(v[n-1]!=v[n-2])
        {
            v[j]=v[n-1];
            j++;
        }
        else
        {
            v[j]=v[n-1];
            j++;
            string t=to_string(c);
             for(int i=0;i<t.size();i++){
                     v[j++]=t[i];
                 }
            
        }
        
     return j ;
     
//         int n = v.size();
//         if(n==1) return 1;
//         int i=0,j=0;
//         while(i<n){
//             int c=1;
//             while(i<n-1 && v[i]==v[i+1]){
//                 c++;
//                 i++;
//             }
//             v[j++]=v[i++];
//             if(c>1){
//                 string str = to_string(c);
//                 for(int i=0;i<str.size();i++){
//                     v[j++]=str[i];
//                 }
//             }
//         }
        
//         return j;
        
        
// int n = chars.size();
//         if (n == 1) {
//             return 1;
//         }
        
//         int i = 0, j = 0;
//         while (i < n) {
//             int count = 1;
//             while (i < n - 1 && chars[i] == chars[i + 1]) {
//                 count++;
//                 i++;
//             }
            
//             chars[j++] = chars[i++];
//             if (count > 1) {
//                 string countStr = to_string(count);
//                 for (char c : countStr) {
//                     chars[j++] = c;
//                 }
//             }
//         }
        
//         return j;
    }
};
