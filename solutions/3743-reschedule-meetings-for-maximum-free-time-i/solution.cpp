class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gap(n+1);

        for(int i = 1 ; i < n ; i++){
            gap[i] = startTime[i] - endTime[i-1];
        }
        gap[0] = startTime[0]; 
        gap[n] = eventTime - endTime[n-1];

        int sum = 0 , res = 0;
        int i = 0 , j = k;

        for(int p = i ; p <=n && p <= j ; p++)
            sum += gap[p];
        
        res = max(res , sum);

        while(j < n){
            sum -= gap[i++];
            sum += gap[++j];
            res = max(res , sum);
        }

        return res;    
    }
};
