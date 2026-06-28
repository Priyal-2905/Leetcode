class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long long sum = 0;
        
        for(int i = n-1;i >= n-k;i--){
            long long m = (long long)mul*(long long)nums[i];
            if(m > nums[i]){
                sum += m;
                mul--;
            }
            else{
                sum += nums[i];
            }
        }
        return sum;
    }
};
