class Solution {
public:
    static constexpr long long mod = 1e9 + 7;
    
    int power(long long base, long long exp) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size()+1;

        vector<vector<int>> adj(n+1);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        queue<pair<int,int>> q;
        q.push({1,0});

        vector<int> vis(n+1);
        vis[1] = 1;
        int max_depth = 0;

        while(!q.empty()){
            auto [u,depth] = q.front();
            max_depth = max(max_depth,depth);
            q.pop();
            

            for(auto v : adj[u]){
                if(!vis[v]){
                    q.push({v,depth+1});
                    vis[v] = 1;
                }
            }
        }
        if (max_depth == 0) return 0;

        return power(2,max_depth-1);
        
    }
};
