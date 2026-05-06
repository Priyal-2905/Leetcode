class Solution {
public:
    bool isSafe(int n, vector<string>& grid, int row, int col) {
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
    void solve(int n,vector<string>& grid,int row,int &res){
        if(row == n){
            res = res+1;
            return;
        }

        for(int i = 0;i < n;i++){
            if(isSafe(n,grid,row,i)){
                grid[row][i] = 'Q';
                solve(n,grid,row+1,res);
                grid[row][i] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        int res = 0;
        vector<string> grid(n,string(n,'.'));
        solve(n,grid,0,res);
        return res;
    }
};
