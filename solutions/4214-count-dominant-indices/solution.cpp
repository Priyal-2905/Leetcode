class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> avg(n,0);

        for(int i = n-2;i >= 0;i--){
            avg[i] = nums[i+1]+avg[i+1];
        }
        for(int i = 0;i < n-1;i++){
            avg[i] /= (n-i-1);
        }
        int count = 0;

        for(int i = 0;i < n-1;i++){
            if(nums[i] > avg[i]){
                count++;
            }
        }
        return count;
    }
};
