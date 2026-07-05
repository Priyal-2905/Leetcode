class Solution {
public:
    int range(int num){
        int maxi = num%10;
        int mini = num%10;
        
        while(num > 0){
            int a = num%10;
            maxi = max(a,maxi);
            mini = min(a,mini);
            num /= 10;
        }
        return maxi-mini;
    }
    int maxDigitRange(vector<int>& nums) {
        int maxr = INT_MIN;
        int res = 0;

        for(int num:nums){
            maxr = max(maxr,range(num));
        }

        for(int num:nums){
            if(range(num) == maxr){
                res += num;
            }
        }
        return res;
    }
};
