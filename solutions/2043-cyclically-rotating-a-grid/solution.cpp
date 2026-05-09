class Solution {
public:
    void builder(vector<vector<int>>& grid,vector<vector<int>>& layers){
        int m = grid.size(),n = grid[0].size();
    
        int l = 0,r = n-1,t = 0,b = m-1;
        while(t < b && l < r){
            vector<int> temp;

            for(int i = l;i < r;i++){
                temp.push_back(grid[t][i]);
            }
            for(int i = t;i < b;i++){
                temp.push_back(grid[i][r]);
            }

            for(int i = r;i > l;i--){
                temp.push_back(grid[b][i]);
            }
            for(int i = b;i > t;i--){
                temp.push_back(grid[i][l]);
            }
            layers.push_back(temp);
            l++;r--;t++;b--;
        }
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>> layers;
        builder(grid,layers);

        for(auto &layer:layers){
            int shift = k % layer.size();
            reverse(layer.begin(), layer.begin() + shift);
            reverse(layer.begin() + shift, layer.end());
            reverse(layer.begin(), layer.end());
        }

        int l = 0,r = n-1,t = 0,b = m-1;
        int x = 0;
        
        while(t < b && l < r){
            vector<int> temp = layers[x++];
            int p = 0;
            for(int i = l;i < r;i++){
                grid[t][i] = temp[p++];
            }
            for(int i = t;i < b;i++){
                grid[i][r] = temp[p++];
            }

            for(int i = r;i > l;i--){
                grid[b][i] = temp[p++];
            }
            for(int i = b;i > t;i--){
                grid[i][l] = temp[p++];
            }
            l++;r--;t++;b--;
        }

        return grid;
        
    }
};
