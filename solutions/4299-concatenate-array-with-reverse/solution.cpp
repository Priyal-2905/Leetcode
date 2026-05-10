class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> temp;

        for(int n : nums){
            temp.push_back(n);
        }
        reverse(temp.begin(),temp.end());
        
        for(int n:temp){
            nums.push_back(n);
        }
        return nums;
    }
};
