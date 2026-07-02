class Solution {
public: 
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(),n = grid[0].size();

        health -= grid[0][0];
        if(health <= 0){return false;}

        vector<vector<int>> best(m,vector<int>(n,-1));
        best[0][0] = health;

        priority_queue<vector<int>> pq;
        pq.push({health, 0, 0});

        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};

        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int h = cur[0];
            int x = cur[1];
            int y = cur[2];

            if(x == m-1 && y == n-1){return true;}

            if(h < best[x][y]){continue;}
            
            
            for(int i = 0;i < 4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || nx == m || ny < 0 || ny == n){continue;}

                int nh = h - grid[nx][ny];

                if(nh > 0 && nh > best[nx][ny]){
                    best[nx][ny] = nh;
                    pq.push({nh,nx,ny});
                }
            }
        }
        return false;
    }
};
