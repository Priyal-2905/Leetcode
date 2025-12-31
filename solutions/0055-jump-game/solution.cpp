class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        int end = nums.size() - 1;

        if(nums[0] == 0 && end == 0){return true;}

        for(int i = 0;i <= end;i++){
            if (i > maxIndex){
                return false;
            }
            maxIndex = max(maxIndex,i + nums[i]);
            if(maxIndex >= end){
                return true;
            }
            
        }
        return false;
    }
};
