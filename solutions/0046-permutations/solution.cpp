class Solution {
public:

        void makePermutation(vector<vector<int>>& res,vector<int> nums,int l,int r){

        if(l==r){
            res.push_back(nums);
            return;
        }

        for(int i=l;i<r;i++){
            swap(nums[i],nums[l]);
            makePermutation(res,nums,l+1,r);
            swap(nums[i],nums[l]);

        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
      int l=0;
      int r=nums.size();
      vector<vector<int>> res;
      vector<int> temp;

      makePermutation(res,nums,l,r);
      return res;

    }

  
};
