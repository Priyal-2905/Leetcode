class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<long long> rsum(m,0);
        vector<long long> csum(n,0);

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                rsum[i] += grid[i][j];
            }
        }

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                csum[i] += grid[j][i];
            }
        }

        long long total = 0,prefix = 0;

        for(auto r:rsum){total += r;}

        for(auto r:rsum){
            prefix += r;
            if(prefix*2 == total){return true;}

        }
        total = 0;
        prefix = 0;
        for(auto r:csum){total += r;}

        for(auto r:csum){
            prefix += r;
            if(prefix*2 == total){return true;}
        }
        

        return false;
    }
};
