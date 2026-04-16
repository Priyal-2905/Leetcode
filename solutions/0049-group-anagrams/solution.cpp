class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        if(n == 0){return {{""}};}
        if(n == 1){return {{strs[0]}};}

        vector<string> cp = strs;
        vector<bool> visited(n,false);
        vector<vector<string>> res;

        for(auto &s : cp){
            sort(s.begin(),s.end());
        }

        for(int i = 0;i < n;i++){
            if(visited[i]){continue;}
            visited[i] = true;
            vector<string> temp;
            temp.push_back(strs[i]);
            for(int j = i+1;j < n;j++){
                if(j < n && cp[i] == cp[j]){
                    visited[j] = true;
                    temp.push_back(strs[j]);
                }
            }
            res.push_back(temp);
        }
        return res;

    }
};
