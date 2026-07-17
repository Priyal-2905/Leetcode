class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        dist[0][0] = 0;
        pq.push({0,{0,0}});

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        while(!pq.empty()){
            auto [cost,cell] = pq.top();
            pq.pop();
            int r = cell.first;
            int c = cell.second;

            if (r == m - 1 && c == n - 1)
                return cost;

            if (cost > dist[r][c])
                continue;

            for(int i = 0;i < 4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    int edge = abs(heights[r][c] - heights[nr][nc]);
                    int newCost = max(cost,edge);

                    if(newCost < dist[nr][nc]){
                        dist[nr][nc] = newCost;
                        pq.push({newCost, {nr, nc}});

                    }
                }
            }
        }
        return 0;
    }
};
