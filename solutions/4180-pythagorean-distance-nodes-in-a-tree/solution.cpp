class Solution {
public:
    vector<int> bfs(int n,vector<vector<int>>& adj,int src){
        vector<int> dist(n,-1);
        queue<int> q;
        dist[src] = 0;
        q.push(src);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v:adj[u]){
                if(dist[v] == -1){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);

        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> dx = bfs(n,adj,x);
        vector<int> dy = bfs(n,adj,y);
        vector<int> dz = bfs(n,adj,z);

        int count  = 0;
        for (int i = 0; i < n; i++) {
            if (dx[i] == -1 || dy[i] == -1 || dz[i] == -1)
                continue;
        
            vector<int> d = {dx[i], dy[i], dz[i]};
            sort(d.begin(), d.end());
            
            if (1LL * d[0] * d[0] + 1LL * d[1] * d[1] == 1LL * d[2] * d[2]) {
                count++;
            }
        }
        return count;
    }
};
