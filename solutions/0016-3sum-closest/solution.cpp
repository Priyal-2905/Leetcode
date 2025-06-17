class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       sort(nums.begin(),nums.end());
       int res = INT_MAX /2;

        for(int i=0;i<nums.size();i++){
            int low = i+1;
            int high = nums.size()-1;

            while(low<high){
                int sum = nums[i]+nums[low]+nums[high];
                 res = (abs(res-target) < abs(target - sum))?res:sum;
               
               if(sum==target) return sum;
               else if(sum<target){
                
                    low++;
                }
                else{
                     
                    high--;
                }
                     
            }
        } 
        return res;
    }
};
