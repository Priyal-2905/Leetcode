class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        // set<vector<int>> s;
        
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;

            for(int j=i+1;j<n;j++){
              if(j>i+1 && nums[j] == nums[j-1]) continue;

                int low = j+1;
                int high = n-1;

                while(low<high){
                   long long sum = (long long)nums[low] + nums[high] + nums[i]+nums[j];

                    if(sum==target){
                        res.push_back({nums[low] ,nums[high] , nums[i],nums[j]});
                        low++;

                        while(low<high && nums[low] == nums[low-1]) low++;
                       
                    }
                    else if(sum < target){
                        low++;
                    }
                    else{
                        high--;
                    }   
                }
            }
        }
        // for(auto i :s)
        //     res.push_back(i);

        return res;
    }
};
