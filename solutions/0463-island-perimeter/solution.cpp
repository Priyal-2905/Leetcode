class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int peri = 0;

        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int sx = 0,sy = 0;

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1){
                    sx = i;
                    sy = j;
                }
            }
        }

        queue<pair<int,int>> q;
        vis[sx][sy] = true;
        q.push({sx,sy});

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(int i = 0;i < 4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 || ny < 0 || nx == m || ny == n){
                    peri++;
                    continue;
                }
                if(grid[nx][ny] == 0 ){
                    peri++;
                }
                else if(!vis[nx][ny]){
                    q.push({nx,ny});
                    vis[nx][ny] = true;
                }

            }
        }
        return peri;
    }
};
