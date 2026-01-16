class Solution {
public:
    int path(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        
        if(i >= grid.size()|| j>=grid[0].size()){
            return 0;
        }
        if(grid[i][j] == 1){
            return 0;
        }
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        dp[i][j] = path(i+1,j,grid,dp) + path(i,j+1,grid,dp);
        return dp[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(),n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return path(0,0,obstacleGrid,dp);
    }
};
