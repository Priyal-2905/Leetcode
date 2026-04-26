class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        for(int i = 0; i < n; i++){
            bool flag = true;

            for(int j = i + 1; j < n; j++){
                if(nums[j] >= nums[i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                res.push_back(nums[i]);
                continue;
            }

            flag = true;

            for(int j = i - 1; j >= 0; j--){
                if(nums[j] >= nums[i]){
                    flag = false;
                    break;
                }
            }

            if(flag){
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
