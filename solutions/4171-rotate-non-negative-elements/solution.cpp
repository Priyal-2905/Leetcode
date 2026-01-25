class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> non_neg;

        for(int i = 0;i < nums.size();i++){
            if(nums[i] >= 0){
                non_neg.push_back(nums[i]);
            }
        }
        int m = non_neg.size();

        if(m == 0 || m == 1){return nums;}

        k = k % m;
        reverse(non_neg.begin(),non_neg.begin()+k);
        reverse(non_neg.begin()+k , non_neg.end());
        reverse(non_neg.begin(),non_neg.end());

        int j = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] >= 0){
                nums[i] = non_neg[j++];
            }
        }
        return nums;
    }
};
