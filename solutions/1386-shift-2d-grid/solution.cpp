class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> temp;
        for(auto row : grid){
            for(int x : row){
                temp.push_back(x);
            }
        }

        int n = temp.size();
        k = k%n;
        reverse(temp.begin(),temp.end());
        reverse(temp.begin(),temp.begin()+k);
        reverse(temp.begin()+k,temp.end());

        int i = 0;
        for(auto &row : grid){
            for(auto &x : row){
                x = temp[i++];
            }
        }

        return grid;
    }
};
