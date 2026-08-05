class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for(auto x : invocations){
            adj[x[0]].push_back(x[1]);
        }

        unordered_set<int> sus;
        queue<int> q;
        sus.insert(k);
        q.push(k);

        while(!q.empty()){
            int u = q.front();

            for(int v : adj[u]){
                if(!sus.contains(v)){
                    sus.insert(v);
                    q.push(v);
                }
            }
            q.pop();
        }

        bool flag = false;
        for(auto x : invocations){
            int u = x[0];
            int v = x[1];

            if(!sus.contains(u) && sus.contains(v)){
                flag = true;
                break;
            }
        }
        vector<int> res;

        for(int i = 0;i < n;i++){
            if(!flag && sus.contains(i)){
                continue;
            }
            res.push_back(i);
        }

        return res;

    }
};
