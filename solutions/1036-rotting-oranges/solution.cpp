class Solution {
public:
    void bfs(vector<vector<int>>& grid,vector<vector<int>>& dist, int sx,int sy){
        int m = grid.size(),n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        queue<pair<int,int>> q;
        q.push({sx,sy});
        vis[sx][sy] = true;
        dist[sx][sy] = 0;

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        while(!q.empty()){
            auto [x,y]= q.front();
            q.pop();

            for(int i = 0;i < 4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx == m || ny == n || grid[nx][ny] != 1){
                    continue;
                }

                if(!vis[nx][ny] ){
                    dist[nx][ny] = min(dist[nx][ny],dist[x][y] + 1);
                    vis[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        bool flag = true;

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1){flag = false;}

                if(grid[i][j] == 2){
                    bfs(grid,dist,i,j);
                }
            }
        }

        if(flag){return 0;}

        int res = INT_MIN;

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1 && dist[i][j] == INT_MAX){
                    return -1;
                }
                if(grid[i][j] == 1){
                    res = max(res,dist[i][j]);
                }
            }
        }

        return res;
        
    }
};
