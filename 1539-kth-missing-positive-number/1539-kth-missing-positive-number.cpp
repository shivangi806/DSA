class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l =0,h=arr.size();
        // find first index jha arr[i]-i > k ho rha 
        while(l<h){
            int mid = (l+h)/2;
            if(arr[mid]-mid > k){ // mtlb number of missing elements k se jyada h 
                // to mid se piche check karo
                h=mid;
            }
            else l=mid+1;
        }
        return l+k;
    }
};