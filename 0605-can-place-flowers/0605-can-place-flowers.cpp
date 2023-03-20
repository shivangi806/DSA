class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int c=0;
        int len = flowerbed.size();
        if(len==1){
            if(flowerbed[0]==0) return 1;
        }
        if(flowerbed[0]==0 && flowerbed[1]==0){
            c++;
            flowerbed[0]=1;
        }
        if(flowerbed[len-1]==0 && flowerbed[len-2]==0){
            flowerbed[len-1]=1;
            c++;
        }
        for(int i=1;i<len-1;i++){
            if(flowerbed[i]==0){
                if(flowerbed[i-1]==0 && flowerbed[i+1]==0){
                  c++; 
                  flowerbed[i]=1 ;
                } 
            }
        }
        if(c>=n) return 1;
        return 0;
    }
};