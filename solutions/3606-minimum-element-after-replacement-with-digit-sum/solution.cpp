class Solution {
public:
    int sum_digit(int num){
        int sum = 0;
        while(num != 0){
            sum += num % 10;
            num = num/10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        for(int i = 0;i < nums.size();i++){
            nums[i] = sum_digit(nums[i]);
        }

        auto it = min_element(nums.begin(),nums.end());
        return *it;
    };
};
