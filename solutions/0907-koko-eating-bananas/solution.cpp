class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1,high = 0;
        int res = 0;
        for (int x : piles) {
            high = max(high, x);
        }

        while(low <= high){
            int mid = low + (high - low)/2;

            long hours = 0;
            for(int x : piles){
                hours += (x + mid - 1) / mid; // ceil
            }

            if(hours <= h){
                res = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return res;
    }
};
