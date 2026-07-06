class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);

        for(auto edge : prerequisites){
            adj[edge[0]].push_back(edge[1]);
        }

        vector<int> indegree(n,0);

        for (int u = 0; u < n; u++) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }

        queue<int> q;

        for(int i = 0;i < n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(int neighbour : adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }

        return topo.size() == n;
    }
};
