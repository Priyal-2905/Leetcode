class Solution {
public:
    int sum(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp){

        if(i == grid.size()-1 && j == grid[0].size()-1){
            return grid[i][j];
        }

        if(i >= grid.size() || j >= grid[0].size()){
            return INT_MAX;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        dp[i][j] = grid[i][j] + min(sum(grid,i+1,j,dp),sum(grid,i,j+1,dp));
        return dp[i][j];
    
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return sum(grid,0,0,dp);
    }
};
