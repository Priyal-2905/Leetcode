class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<bool>> present(m,vector<bool>(n,false));
        vector<vector<int>> sum(m,vector<int>(n));

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 'X'){
                    sum[i][j] = 1;
                }
                else if(grid[i][j] == 'Y'){
                    sum[i][j] = -1;
                }
                else{
                    sum[i][j] = 0;
                }
                present[i][j] = (grid[i][j] == 'X') || (i > 0 && present[i-1][j]) || (j > 0 && present[i][j-1]);
            }
        }

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(i > 0){sum[i][j] += sum[i-1][j];}
                if(j > 0){sum[i][j] += sum[i][j-1];}
                if(i > 0 && j > 0){sum[i][j] -= sum[i-1][j-1];}
            }
        }
        
        int res = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(sum[i][j] == 0 && present[i][j]){
                    res++;
                }
            }
        }

        return res;
    }
};
