class Solution {
public:
    bool verfiy(int x,long long sum){
        if(sum % 10 != x){
            return false;
        }
        int d = sum%10;
        
        while(sum != 0){
            d = sum % 10;
            sum = sum/10;
        }

        return d == x;
        
    }
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int count = 0;

        for(int i = 0;i < n;i++){
            long long sum = 0;
            for(int j = i;j < n;j++){
                sum += nums[j];
                if(verfiy(x,sum)){
                    count++;
                }
            }
        }
        return count;
    }
};
