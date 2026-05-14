class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size()-1;
        if(n == 0){return false;}
        sort(nums.begin(),nums.end());

        if(nums[n] != n || nums[n-1] != n){return false;}

        for(int i = 1;i < n;i++){
            if(nums[i-1] != i){return false;}
        }
        return true;
        
    }
};
