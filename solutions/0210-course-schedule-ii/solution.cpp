class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);

        for(auto edge : prerequisites){
            adj[edge[0]].push_back(edge[1]);
        }

        vector<int> indegree(n,0);

        for(int i = 0;i < n;i++){
            for(int u : adj[i]){
                indegree[u]++;
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
        if(topo.size() < n){
            return {};
        }

        reverse(topo.begin(),topo.end());
        return topo;

    }
};
