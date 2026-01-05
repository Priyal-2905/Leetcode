class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long res = 0;

        int mini = abs(matrix[0][0]);
        int count = 0;

        for(auto row:matrix){
            for(int x:row){
                if(x < 0){count++;}

                res += abs(x);
                mini = min(mini,abs(x));
            
            }
        }
        if(count%2 != 0){
            res -= 2*mini;
        }
       
        return res;
    }
};
