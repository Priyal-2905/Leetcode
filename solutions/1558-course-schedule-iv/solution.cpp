class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        int m = queries.size();
        vector<vector<int>> adj(n);

        for(auto edge : prerequisites){
            adj[edge[0]].push_back(edge[1]);
        }

        vector<int> indegree(n,0);
        vector<vector<bool>> ispre(n,vector<bool>(n,false));// is i prereq of j?

        for(int i = 0;i < n;i++){
            for(int node : adj[i]){
                indegree[node]++;
                ispre[i][node] = true;
            }
        }

        queue<int> q;
        for(int i = 0;i < n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
    
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
        
            for(int neighbour : adj[node]){
                for(int i = 0;i < n;i++){
                    if(ispre[i][node]){
                        ispre[i][neighbour] = true;
                    }
                }

                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }

        vector<bool> res;

        for(auto query : queries){
            if(ispre[query[0]][query[1]])
                res.push_back(true);
            else
                res.push_back(false);
        }

        return res;
    }
};
