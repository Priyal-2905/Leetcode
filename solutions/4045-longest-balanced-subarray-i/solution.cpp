class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = 0;i < n;i++){
            unordered_map<int,int> even,odd;
            for(int j = i;j < n;j++){
                if(nums[j] % 2){
                    odd[nums[j]] = 1;
                }
                else{
                    even[nums[j]] = 1;
                }

                if(even.size() == odd.size()){
                    res = max(res,j-i+1);
                }
            }
        }
        return res;
    }
};
