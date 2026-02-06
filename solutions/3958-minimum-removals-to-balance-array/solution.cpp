class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res = 0,i = 0,j = 0;
        int n = nums.size();
        while(j < n){
            if(nums[j] <= 1LL*nums[i]*k) j++;
            else i++;
            res = max(res,j-i+1);
        }
        return n-res+1;
    }
};
