class Solution {
public:
    void bfs(vector<vector<char>>& board, vector<vector<bool>>& safe,int sx,int sy){
       int m = board.size(),n = board[0].size();
        // vector<vector<int>> vis(m,vector<bool>(n,false));

        queue<pair<int,int>> q;
        // vis[sx][sy] = true;
        safe[sx][sy] = true;
        q.push({sx,sy});

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(int i = 0;i < 4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx == m || ny == n || board[nx][ny] == 'X'){
                    continue;
                }

                if(!safe[nx][ny]){
                    safe[nx][ny] = true;  
                    q.push({nx,ny});  
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
       int m = board.size(),n = board[0].size();
       vector<vector<bool>> safe(m,vector<bool>(n,false));

       for(int i = 0;i < n;i++){
            if(board[0][i] == 'O' && !safe[0][i]){
                bfs(board,safe,0,i);
            }
        }

        for(int i = 1;i < m;i++){
            if(board[i][n-1] == 'O'&& !safe[i][n-1]){
                bfs(board,safe,i,n-1);
            }
        }

        for(int i = 0;i < n-1;i++){
            if(board[m-1][i] == 'O' && !safe[m-1][i]){
                bfs(board,safe,m-1,i);
            }
        }

        for(int i = 1;i < m-1;i++){
            if(board[i][0] == 'O' && !safe[i][0]){
                bfs(board,safe,i,0);
            }
        }

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(board[i][j] == 'O' && !safe[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
