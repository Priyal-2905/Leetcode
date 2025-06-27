class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        subset(nums,s,0);
        return vector<vector<int>>(s.begin(), s.end());
    }

    void subset(vector<int> &nums, set<vector<int>>& s,int index){
        
        if(index==nums.size()){
            s.insert(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            subset(nums,s,index+1);
            swap(nums[i],nums[index]);
        }
    }
};
