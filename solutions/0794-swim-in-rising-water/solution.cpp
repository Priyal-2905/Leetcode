class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        vector<vector<pair<int,int>>> parent(
            m, vector<pair<int,int>>(n, {-1, -1})
        );

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [time, pos] = pq.top();
            pq.pop();

            int r = pos.first;
            int c = pos.second;

            if (time != dist[r][c])
                continue;

            if (r == m - 1 && c == n - 1)
                break;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                int newTime = max(time, grid[nr][nc]);

                if (newTime < dist[nr][nc]) {
                    dist[nr][nc] = newTime;

                    parent[nr][nc] = {r, c};

                    pq.push({newTime, {nr, nc}});
                }
            }
        }

        vector<pair<int,int>> path;

        int r = m - 1;
        int c = n - 1;

        while (r != -1 && c != -1) {
            path.push_back({r, c});

            auto [pr, pc] = parent[r][c];

            r = pr;
            c = pc;
        }

        reverse(path.begin(), path.end());
        return dist[m - 1][n - 1];
    }
};
