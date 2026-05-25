class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int res = INT_MIN;

        for (int i = 0; i < m; i++) {
            int curr = grid[i][0];
            for (int j = 1; j < n; j++) {
                res = max(res, curr + grid[i][j]);
                curr = max(grid[i][j], curr + grid[i][j]);
            }
        }

        for (int j = 0; j < n; j++) {
            int curr = grid[0][j];
            for (int i = 1; i < m; i++) {

                res = max(res, curr + grid[i][j]);
                curr = max(grid[i][j], curr + grid[i][j]);
            }
        }

        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                res = max(res, grid[i][j]);
            }
        }
        return res;
    }
};
