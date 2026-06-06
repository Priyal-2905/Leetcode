class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> prefix(n),suffix(n),answer(n);

        for(size_t i = 1;i < n;i++){
            prefix[i] = nums[i-1] + prefix[i-1];
            suffix[n-i-1] = suffix[n-i] + nums[n-i];
        }
        for(size_t i = 0;i < n;i++){
            answer[i] = abs(prefix[i] - suffix[i]);
        }
        return answer;
    }
};
