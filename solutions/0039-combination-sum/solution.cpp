class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> res;

        combo(candidates,target,0,0,comb,res);
        return res;       
    }

    void combo(vector<int>& candidates,int target,int total,int index,vector<int> comb, vector<vector<int>>& res){

        if(total == target){
            res.push_back(comb);
            return;
        }
        if(total > target || index >= candidates.size()){ return; }

        comb.push_back(candidates[index]);
        combo(candidates,target,total+candidates[index],index,comb,res);
        comb.pop_back();
        combo(candidates,target,total,index+1,comb,res);

    }
    
};
