class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int res = 0;
        int m = mat.size();
        int n = mat[0].size();

        vector<int> row(m,0);
        vector<int> col(n,0);

        for(int i = 0;i < m;i++){
            int count = 0;
            for(int j = 0;j < n;j++)
                if(mat[i][j] == 1)
                    count++;
            
            row[i] = count;
        }
        for(int i = 0;i < n;i++){
            int count = 0;
            for(int j = 0;j < m;j++)
                if(mat[j][i] == 1)
                    count++;
            
            col[i] = count;
        }

        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                if(mat[i][j] == 1 && row[i] == 1 && col[j] == 1)
                    res++;
        
        return res;
        
    }
};
