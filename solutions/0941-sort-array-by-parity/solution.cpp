class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int i = 0,j = n-1;
        vector<int> ans(n);

        for(int num : nums){
            if(num % 2)
                ans[j--] = num;
            else
                ans[i++] = num;
        }
        return ans;
    }
};
