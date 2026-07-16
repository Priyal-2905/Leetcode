class Solution {
public:
    int countPath(vector<string>& grid){
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,0));

        if(grid[0][0] == '#' || grid[m-1][n-1] == '#'){
            return 0;
        }
        dp[0][0] = 1;

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == '#'){
                    dp[i][j] = 0;
                    continue;
                }

                if(i > 0){dp[i][j] += dp[i-1][j];}
                if(j > 0){dp[i][j] += dp[i][j-1];}
            }
        }
        return dp[m-1][n-1];
    }
        
    vector<string> createGrid(int m, int n, int k) {
        
        vector<string> grid(m,string(n,'.'));
        int paths = countPath(grid);

        if(paths < k){return {};}
        
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(i == 0 && j == 0 || i == m-1 && j == n-1){continue;}
                grid[i][j] = '#';
                int newPaths = countPath(grid);

                if(newPaths < k){
                    grid[i][j] = '.';
                }
                else{
                    paths = newPaths;
                }

                if(paths == k){return grid;}

            }
        }

        return (paths == k)?grid : vector<string>{};
    }
};
