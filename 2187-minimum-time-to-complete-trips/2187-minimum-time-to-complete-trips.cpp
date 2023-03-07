class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        //sort(time.begin(),time.end());
        long long startTime = 1;
        long long endTime= 1e14;
        while(startTime <= endTime){
            long long trip = 0;
            long long mid = startTime + (endTime-startTime)/2 ;
            for(int i=0;i<time.size();i++){
                trip +=  mid / time[i];
            }
            if(trip < totalTrips){
                    // search in right side
                    startTime = mid+1;
                }
                else{
                    endTime = mid-1;
                }
        }
        return startTime;
    }
};