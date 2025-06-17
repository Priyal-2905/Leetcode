class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        
        int n=nums.size();

        for(int i=0;i<n;i++){
            int low=i+1;
            int high=n-1;

            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            while(low<high){
               
                int sum=nums[low]+nums[high]+nums[i];

                if(sum == 0){
                    res.push_back({nums[i], nums[low], nums[high]});
                    low++;
                    while(nums[low]==nums[low-1] && low< high){
                        low++;
                    }
                }
            
                
                else if(sum >0){
                    high--;
                }
                else
                low++;
                
            }
        }
        return res;
    }
};
