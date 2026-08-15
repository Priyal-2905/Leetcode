class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        bool all_zero = true;
        int xo = 0;

        for(int num : nums){
            if(num){all_zero = false;}
            xo = xo^num;
        }

        if(all_zero) return 0;
        if(xo) return n;

        return n-1;

    }
};
