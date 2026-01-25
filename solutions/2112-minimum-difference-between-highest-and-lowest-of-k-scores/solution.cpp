class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int res = nums[k-1] - nums[0];

        for(int i = 0;i+k <= n;i++){
            res  = min(res,nums[i+k-1]-nums[i]);
        }
        return res;
    }   
};
