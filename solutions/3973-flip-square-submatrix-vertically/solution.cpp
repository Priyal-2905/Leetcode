class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size(),n = grid[0].size();
        int arr[k][k];

        for(int i = 0;i < k;i++){
            for(int j = 0;j < k;j++){
                arr[k-i-1][j] = grid[i+x][j+y];
            }
        }

        for(int i = 0;i < k;i++){
            for(int j = 0;j < k;j++){
                grid[i+x][j+y] = arr[i][j];
            }
        }
        return grid;
        
    }
};
