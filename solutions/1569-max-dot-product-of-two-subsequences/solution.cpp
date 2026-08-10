class Solution {
public:

    int solve(vector<int>& nums1,vector<int>& nums2,int i,int j,vector<vector<int>>& dp){
        if(i >= nums1.size() || j >= nums2.size() ){
            return -1e9;
        }

        if(dp[i][j] != -1e9){
            return dp[i][j];
        }
        int curr = nums1[i]*nums2[j];
        int next = solve(nums1,nums2,i+1,j+1,dp);

        int take = curr + max(next,0);

        int skip1 = solve(nums1,nums2,i+1,j,dp);
        int skip2 = solve(nums1,nums2,i,j+1,dp);

        return dp[i][j] = max({take,skip1,skip2});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1e9));
        return solve(nums1,nums2,0,0,dp);
    }
};
