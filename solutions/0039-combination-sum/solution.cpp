class Solution {
public:
    void solve(vector<int>& curr,vector<vector<int>>& res,vector<int>& candidates,int target,int i){
        if(target == 0){
            res.push_back(curr);
            return;
        }

        if(target < 0||i >= candidates.size()){
            return;
        }

        curr.push_back(candidates[i]);
        solve(curr,res,candidates,target - candidates[i],i);
        curr.pop_back();
        solve(curr,res,candidates,target,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        solve(curr,res,candidates,target,0);
        return res;
    }
};
