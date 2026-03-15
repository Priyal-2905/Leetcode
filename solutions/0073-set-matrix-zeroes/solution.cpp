class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> zeros;
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                if(matrix[i][j] == 0)
                    zeros.push_back({i,j});
                

        for(auto &z : zeros) {
            int r = z[0];
            int c = z[1];

            for(int j = 0; j < n; j++)
                matrix[r][j] = 0;

            for(int i = 0; i < m; i++)
            matrix[i][c] = 0;
        }      
                                                                               
        
    }
};
