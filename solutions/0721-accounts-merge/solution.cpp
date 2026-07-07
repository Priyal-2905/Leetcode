class Solution {
public:
    vector<int> rank,parent;

    int find(int x){
        if(parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    void unite(int x,int y){
        int px = find(x);
        int py = find(y);

        if(px == py)
            return;
        if(rank[px]  < rank[py])
            parent[px] = py;
        else {
            parent[py] = px;
            if(rank[px] == rank[py])
                rank[px]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        parent.resize(n);
        rank.assign(n,0);

        for(int i = 0;i < n;i++)
            parent[i] = i;
        
        unordered_map<string,int> emailToAcc;

        for(int i = 0;i < n;i++){
            for(int j = 1;j < accounts[i].size();j++){
                string email = accounts[i][j];
                if(emailToAcc.contains(email))
                    unite(i,emailToAcc[email]);
                else
                    emailToAcc[email] = i;
                
            }
        }

        unordered_map<int,set<string>> um;
        
        for(auto it : emailToAcc){
            int p = it.second;
            string mail = it.first;
            int root = find(p);

            um[root].insert(mail);
        }

        vector<vector<string>> res;

        for(auto it : um){
            vector<string> temp;
            temp.push_back(accounts[it.first][0]);

            for(auto email : it.second)
                temp.push_back(email);
            

            res.push_back(temp);
        }

        return res;
    }
};
