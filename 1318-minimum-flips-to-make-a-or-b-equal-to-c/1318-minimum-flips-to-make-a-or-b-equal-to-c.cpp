class Solution {
public:
    
    void dtoB(int a,vector<int>&arr)
    {
        int i=0;
        while(a>0)
        {
            arr[i]=a%2;
            a=a/2;
            i++;
        }
    }
    int minFlips(int a, int b, int c) {
        vector<int> arr(32,0) , brr(32,0) , crr(32,0);
        dtoB(a,arr);
        dtoB(b,brr);
        dtoB(c,crr);
        int ans =0;
        for(int i=0;i<32;i++)
        {
            if((arr[i] | brr[i]) != crr[i])
            {
                if((arr[i]==1|brr[i]==1) && crr[i]==0)
                {
                    if(arr[i]==1 && brr[i]==1)
                    {
                        ans+=2;
                    }
                    else
                    {
                        ans++;
                    }
                }
                else
                    ans++;
            }
        }
        return ans ;
    }
};