class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {

        for(int i = 0;i < arrivalTime.size();i++){
            arrivalTime[i] %= period;
        }

        int maxi = *max_element(lights.begin(),lights.end());

        int ans = 0;
        for(int time : arrivalTime){
            if(time >= maxi){
                ans = max(ans,period-time);
            }
        }

        return ans;
        
    }
};
