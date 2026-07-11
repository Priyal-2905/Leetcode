class Solution {
public:
    bool bfs(vector<vector<int>>& adj,vector<bool>& visited,int start){
        queue<int> q;
        q.push(start);
        visited[start] = true;
        int nodes = 0;
        int edges = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            nodes++;
            edges += adj[node].size();

            for(auto v : adj[node]){
                if(!visited[v]){
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        edges /= 2;

        int a = nodes *(nodes-1)/2;

        return a == edges;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);
        int count = 0;

        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(int i = 0;i < n;i++){
            if(!visited[i]){
                if(bfs(adj,visited,i)){
                    count++;
                }
            }
        }
        return count;
    }
};
