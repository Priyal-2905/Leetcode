class Solution {
public:
    int jump(vector<int>& nums) {

    if (nums.size() == 1) return 0;

    int jumps = 0;
    int i = 0;

    while (i < nums.size()) {
        if (i + nums[i] >= nums.size() - 1) {
            return jumps + 1;
        }

        int maxReach = 0;
        int nextIndex = i;

        for (int j = i + 1; j <= i + nums[i]; j++) {
            if (j + nums[j] > maxReach) {
                maxReach = j + nums[j];
                nextIndex = j;
            }
        }

        i = nextIndex;
        jumps++;
    }

        return jumps;
        
        
    }
};
