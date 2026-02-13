class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        res.push_back({});
        int start = 0,end = 0;
        
        for(int i = 0;i < n;i++){
            start = 0;
            if(i > 0 && nums[i] == nums[i - 1])
                start = end + 1;

            end = res.size() - 1;
            int size = res.size();
            for(int j = start; j < size; j++) {
                vector<int> temp = res[j];
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }
        return res;
    }
};
