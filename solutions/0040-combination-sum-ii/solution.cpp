class Solution {
public: 
     vector<vector<int>> res;
    void solve(vector<int>& candidates,int target,int start,vector<int> temp){
        if(target == 0){
            res.push_back(temp);
            return;
        }
        if(target < 0){
            return;
        }

        for(int i = start;i < candidates.size();i++){
            if(i > start && candidates[i-1] == candidates[i]){
                continue;
            }
            if (candidates[i] > target)
                break;
            temp.push_back(candidates[i]);
            solve(candidates,target - candidates[i],i+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(candidates, target, 0, temp);
        return res;
    }
};
