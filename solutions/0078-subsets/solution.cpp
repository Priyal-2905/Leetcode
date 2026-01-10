class Solution {
public:

    void make(vector<int>&temp ,vector<vector<int>>& res,int index,vector<int>& nums){
        if(index == nums.size()){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        make(temp,res,index+1,nums);
        temp.pop_back();
        make(temp,res,index+1,nums);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        make(temp,res,0,nums);
        return res;
    }
};
