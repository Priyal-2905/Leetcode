class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = nums[0];

        for(int i = 1;i < nums.size();i++){
            if(nums[i-1] > nums[i]){
                res = nums[i];
                break;
            }
        }
        return res;
    }
};
