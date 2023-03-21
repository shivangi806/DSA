class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mt) {
        int nr = mt.size();
        int nc = mt[0].size();
        
        int left = 0;
        int right = nc-1;
        int top = 0;
        int down = nr -1 ;
        
        vector<int> ans ;
        int dir=0;
        while( top<=down && left<=right){
         if(dir==0){
            for(int i = left ; i <=right;i++){
            // top is fixed
             ans.push_back(mt[top][i]);
         }  
             top++;
         } 
         else if(dir==1){
         for(int i = top ; i <= down;i++){
             ans.push_back(mt[i][right]);
             
         }   
             right--;
         }
         else if(dir==2){
         for(int  i = right ; i>=left;i--){
              ans.push_back(mt[down][i]);
              
         }    
             down--;
         }
         else if(dir==3){
         for(int i = down ; i>=top ; i--){
             ans.push_back(mt[i][left]);
             
         }   
             left++;
             
         }
        dir = (dir+1)%4 ;
        }
        return ans ;
    }
};