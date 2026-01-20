class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sol;
        vector<string> grid(n,string(n,'.'));
        solve(sol,grid,0,n);
        return sol;
      
    }
    
    void solve(vector<vector<string>>& sol,vector<string>& grid,int row,int n){
        if(row == n){
            sol.push_back(grid);
            return;
        }

        for(int col = 0; col < n;col++){
            if(isValid(n,grid,row,col)){
                grid[row][col] = 'Q';
                solve(sol,grid,row+1,n);
                grid[row][col] = '.';
            }
        }
    }
    
    bool isValid(int n, vector<string>& grid, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (grid[i][col] == 'Q') {
                return false;
            }
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (grid[i][j] == 'Q') {
                return false;
            }
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (grid[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
};
