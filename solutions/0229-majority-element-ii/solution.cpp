class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        sort(nums.begin(),nums.end());

        int count = 1;

        for (int i = 1; i <= n; i++) {
            if (i < n && nums[i] == nums[i - 1]) {
                count++;
            } else {
                if (count > n / 3) {
                    res.push_back(nums[i - 1]);
                }
                count = 1;
            }
        }
        return res;

    }
};
