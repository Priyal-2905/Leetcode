class Solution {
public:
    void solve(int start,vector<vector<int>>& res,vector<int>& comb,int n,int k){
        if(comb.size() == k){
            res.push_back(comb);
        }

        for(int i = start;i <= n;i++){
            comb.push_back(i);
            solve(i+1,res,comb,n,k);
            comb.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb;

        solve(1,res,comb,n,k);
        return res;
    }
};
