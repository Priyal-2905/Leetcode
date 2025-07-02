class Solution {
public:
     void makeSubset( vector<int> nums , vector<vector<int>>& res , int index ,vector<int> curr){

        if(index == nums.size()){
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        makeSubset(nums , res , index + 1, curr);
        curr.pop_back();
        makeSubset(nums , res , index + 1 , curr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        makeSubset(nums , res , 0 , curr);
        return res;
    }

  
};
