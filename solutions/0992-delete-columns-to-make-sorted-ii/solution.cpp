class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].size();

        vector<bool> sorted(rows - 1, false);
        int res = 0;

        for (int col = 0; col < cols; col++) {
            bool bad = false;

            for (int row = 0; row < rows - 1; row++) {
                if (!sorted[row] && strs[row][col] > strs[row + 1][col]) {
                    bad = true;
                    break;
                }
            }

            if (bad) {
                res++;
            }
            else {
                for (int row = 0; row < rows - 1; row++) {
                    if (!sorted[row] && strs[row][col] < strs[row + 1][col]) {
                        sorted[row] = true;
                    }
                }
            }
        }

        return res;
    }
};
