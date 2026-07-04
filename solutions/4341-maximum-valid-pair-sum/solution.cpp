class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();

        long long res = 0;
        int left = nums[0];

        for(int i = k;i < n;i++){
            left = max(left,nums[i-k]);
            res = max(res,(long long)nums[i]+left);
        }

        return res;
        
    }
};
