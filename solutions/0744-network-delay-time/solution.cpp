class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, INT_MAX);
        // vector<bool> vis(n+1,false);
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto t:times){
            adj[t[0]].push_back({t[1],t[2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        dist[k] = 0;
        pq.push({0,k});

        while(!pq.empty()){
            auto [d,u] = pq.top();
            pq.pop();

            if(d > dist[u]){
                continue;
            }

            // if(vis[u]){continue;}
            // vis[u] = true;

            for(auto [v,wt] : adj[u]){
                if(dist[u]+wt < dist[v]){
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v],v});
                }
            }
        }

        int res = 0;
        for(int i = 1;i <= n;i++){
            if(dist[i] == INT_MAX){
                return -1;
            }
            res = max(dist[i],res);
        }

        return res;
    }
};
