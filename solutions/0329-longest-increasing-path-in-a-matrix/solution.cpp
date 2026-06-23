class Solution {
public:
    int m,n;
    vector<pair<int,int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(dp[i][j] != -1){
           return dp[i][j];
        }
        int maxDist = 1;
        for(auto d : dir){
            int i2 = i + d.first;
            int j2 = j + d.second;

            if(i2 >= 0 && i2 < m && j2 >= 0 && j2 < n && matrix[i2][j2] > matrix[i][j]){
                maxDist = max(maxDist,1 + solve(i2,j2,matrix,dp));
            }
        }
        return dp[i][j] = maxDist;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int ans = INT_MIN;

        vector<vector<int>> dp(m,vector<int>(n,-1));

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                ans = max(ans,solve(i,j,matrix,dp));
            }
        }

        return ans;
    }
};
