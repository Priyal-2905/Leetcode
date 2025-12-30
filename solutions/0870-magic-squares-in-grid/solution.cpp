class Solution {
public:
    bool check(vector<vector<int>>& grid,int row,int col){
        vector<bool> seen(10, false);

        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                int val = grid[i][j];

                if (val < 1 || val > 9 || seen[val]){
                    return false;
                }      
                seen[val] = true;
            }
        }

        for (int i = 0; i < 3; i++) {
            int sum = 0;
            for (int j = 0; j < 3; j++){
                sum += grid[row + i][col + j];
            }
                
            if (sum != 15) {return false;}
        }

        for (int j = 0; j < 3; j++) {
            int sum = 0;
            for (int i = 0; i < 3; i++){
                 sum += grid[row + i][col + j];
            }
            if (sum != 15) {return false;}
        }

        int d1 = 0, d2 = 0;
        for (int i = 0; i < 3; i++) {
            d1 += grid[row + i][col + i];
            d2 += grid[row + i][col + 2 - i];
        }

        if (d1 != 15 || d2 != 15){
            return false;
        }
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int res = 0;

        if(row < 3 || col < 3){return 0;}

        for(int i = 0;i <= row-3;i++){
            for(int j = 0;j <= col-3;j++ ){
                if(check(grid,i,j))
                 res++;
            }
        }
        return res;
    }
};
