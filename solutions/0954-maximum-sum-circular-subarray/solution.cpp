class Solution {
public:
    int normalMax(vector<int>& nums){
        int n = nums.size();

        int res = nums[0];
        int maxEnd = nums[0];

        for(int i = 1;i < n;i++){
            maxEnd = max(maxEnd+nums[i],nums[i]);
            res = max(res,maxEnd);
        }

        return res;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int maxNormal = normalMax(nums);
        int n = nums.size();

        if(maxNormal < 0){
            return maxNormal;
        }

        int sum = 0;
        for(int i = 0;i < n;i++){
            sum += nums[i];
            nums[i] = -nums[i];
        }

        int maxCircular = sum + normalMax(nums);

        return max(maxNormal,maxCircular);
    }
};
