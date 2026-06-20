class Solution {
public:
    int solve(vector<int>& nums,int i,int target,vector<vector<int>>& dp,int sum){
        if(abs(target) > sum){
            return 0;
        }
        if(i == nums.size()){;
            return target == 0;
        }

        if(dp[i][target+sum] != -1){
            return dp[i][target + sum];
        }

        return dp[i][target + sum] = solve(nums,i+1,target-nums[i],dp,sum) + solve(nums,i+1,target+nums[i],dp,sum);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        if(n == 0 || abs(target) > sum){return 0;}

        vector<vector<int>> dp(n, vector<int>(2*sum+1, -1));

        return solve(nums,0,target,dp,sum);

    }
};
