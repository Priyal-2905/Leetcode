class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> max(n),min(n);

        max[0] = nums[0];
        min[n-1] = nums[n-1];

        for(int i = 1;i < n;i++){
            max[i] = (nums[i] > max[i-1])?nums[i]:max[i-1];
        }

        for(int i = n-2;i >= 0;i--){
            min[i] = (nums[i] < min[i+1])?nums[i]:min[i+1];
        }

        for(int i = 0;i < n;i++){
            if(max[i]-min[i] <= k){
                return i;
            }
        }
        return -1;
    }
};
