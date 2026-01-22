class Solution {
public:
    bool isSorted(vector<int>& nums){
        int n = nums.size();
        for(int i = 0;i < n-1;i++){
            if(nums[i+1] < nums[i]){
                return false;
            }
        }
        return true;
    }

    void change(vector<int>& nums,int i){
        nums[i] += nums[i+1];
        nums.erase(nums.begin()+i+1);
    }

    void minpair(vector<int>& nums){
        int res = 0;
        int min = nums[0]+nums[1];
        for(int i = 0;i < nums.size()-1;i++){
            int sum = nums[i] + nums[i+1];
            if(sum < min){
                res = i;
                min = sum;
            }
        }
        change(nums,res);
    }
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;

        while(!isSorted(nums)){
            minpair(nums);
            count++;
        }

        return count;
    }
};
