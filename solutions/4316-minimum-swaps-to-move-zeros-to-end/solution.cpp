class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int low = 0,high = nums.size()-1;
        int res = 0;
        while(low < high){
            if(nums[high] == 0){
                high--;
            }
            else if(nums[low] == 0){
                low++;
                high--;
                res++;
            }
            else{
                low++;
            }
        }
        return res;
    }
};
