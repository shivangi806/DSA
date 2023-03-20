class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int c=0;
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);
        int len = flowerbed.size();
        for(int i=1;i<len-1;i++){
            if(flowerbed[i-1]==0 && flowerbed[i]==0 && flowerbed[i+1]==0){
                c++;
                flowerbed[i-1]=1;
                i++;
            }
        }
        if(c>=n) return 1;
        return 0;
    }
};