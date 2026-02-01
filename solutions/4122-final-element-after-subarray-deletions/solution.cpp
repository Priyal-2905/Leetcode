class Solution {
public:
    int finalElement(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int n = nums.size();
        return max(nums[0],nums[n-1]);
    }
};
