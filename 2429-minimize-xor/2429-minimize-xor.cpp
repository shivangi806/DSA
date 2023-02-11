class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // number of set bits in num2
        int c2=0;
        for(int i=0;i<32;i++){
            c2+=(num2>>i)&1;
        }
        
        
        // number of set bits in num1
//         int c1=0;
//         for(int i=0;i<32;i++){
//             c1+=(num1>>i)&1;
//         }
        
        
        int ans = 0 ;
        // yha pr ya to c2 > c1  or c1==c2
        //if(c2==c1) return num1;
        // required number of set bits  in num1
        //int x = abs(c2-c1); // hame itne bits ko or set karna h from right to left
        
        
        for(int i=31;i>=0 && c2 ;i--){
            if((num1>>i)&1){
                ans|=(1<<i);
                c2--;
            }
        }
        for(int i=0;i<32 && c2;i++){
            if(!((num1>>i)&1)){
                ans|=(1<<i);
                c2--;
            }
        }
        
        return ans ;
        
    }
};