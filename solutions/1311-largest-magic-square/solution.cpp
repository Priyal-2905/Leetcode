class Solution {
public:
    bool check(vector<vector<int>>& grid,int i,int j,int k){
        int sum = 0;

        for (int x = i; x < i + k; x++) {
            int s = 0;
            for (int y = j; y < j + k; y++)s += grid[x][y];
            if (x == i)sum = s;
            else if (sum != s)return false;
        }

        for (int y = j; y < j + k; y++) {
            int s = 0;
            for (int x = i; x < i + k; x++) s += grid[x][y];
            if(sum != s)return false;
        }

        int s = 0;
        for (int d = 0; d < k; d++) s += grid[i + d][j + d];
        if (s != sum) return false;

        s = 0;
        for (int d = 0; d < k; d++) s += grid[i + d][j + k - 1 - d];
        if (s != sum) return false;

        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int res = 1;
        int m = grid.size(),n = grid[0].size();

        for(int k = 2;k <= min(m,n);k++){
            for(int i = 0;i+k <= m;i++){
                for(int j = 0;j+k <= n;j++){
                    if(check(grid,i,j,k)){res = max(res,k);}
                }
            }
        }
        return res;
    }
};
