class Solution {
public:
    void bfs(vector<vector<char>>& grid,vector<vector<bool>>& vis,int sx,int sy){  
        int m = grid.size(),n = grid[0].size();
        queue<pair<int,int>> q;
        q.push({sx,sy});
        vis[sx][sy] = true;

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(int i = 0;i < 4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx == m || ny == n || grid[nx][ny] == '0'){
                    continue;
                }
                
                if(!vis[nx][ny]){
                    vis[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int count = 0;

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    count++;
                    bfs(grid,vis,i,j);
                }
            }
        }
        return count;
    }
};
