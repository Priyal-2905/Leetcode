class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int i = 1;
        int count = 1;
        while(i < nums.size()){
            if(nums[i] != nums[i-1]){
                count = 1;
            }else{
                count++;
            }

            if(count > k){
                nums.erase(nums.begin()+i);
                continue;
            }
            i++;
        }
        return nums;
    }
};
