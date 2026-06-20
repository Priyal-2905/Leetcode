class Solution {
public:
    long long dfs(int u,vector<vector<int>>& adj,vector<int> & baseTime){
        if(adj[u].size() == 0){
            return baseTime[u];
        }

        long long mini = LLONG_MAX;
        long long maxi = LLONG_MIN;

        for(int v:adj[u]){
            long long time = dfs(v,adj,baseTime);
            mini = min(time,mini);
            maxi = max(time,maxi);
        }

        long long time = (maxi - mini) + baseTime[u];
        return maxi + time;
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>>adj(n);

        for(int i = 0;i < n-1;i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
        }

        return dfs(0,adj,baseTime);
    }
};
