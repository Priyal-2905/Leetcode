class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> prefix(m+1,vector<int>(n+1,0));

        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                prefix[i][j] = mat[i-1][j-1] + prefix[i-1][j]+prefix[i][j-1] - prefix[i-1][j-1];
            }
        }

        auto valid = [&](int len){

            for (int i = len; i <= m; i++) {
                for (int j = len; j <= n; j++) {
                    int r = i - len;
                    int c = j - len;
                    int sum = prefix[i][j]
                            - prefix[r][j]
                            - prefix[i][c]
                            + prefix[r][c];

                    if (sum <= threshold)
                        return true;
                }
            }
            return false;
        };

        int low = 0,high = min(m,n);
        int res = 0;
        while(low <= high){
            int mid = (low+high)/2;

            if(valid(mid)){
                res = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return res;
    }
};

