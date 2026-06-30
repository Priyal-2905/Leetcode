class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> indeg,outdeg;

        if(n == 1){return 1;}

        for(auto t : trust){
            indeg[t[1]]++;
            outdeg[t[0]]++;
        }

        for(auto x : indeg){
            if(x.second == n-1 && outdeg[x.first] == 0){
                return x.first;
            }
        }
        return -1;
    }
};
