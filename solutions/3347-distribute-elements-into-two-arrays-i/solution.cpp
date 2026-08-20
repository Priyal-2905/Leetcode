class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> nums1 = {nums[0]};
        vector<int> nums2 = {nums[1]};

        for(int k = 2;k < nums.size();k++){
            if(nums1.back() > nums2.back()){
                nums1.push_back(nums[k]);
            }else{
                nums2.push_back(nums[k]);
            }
        }
        vector<int> ans = nums1;

        for(auto num : nums2){
            ans.push_back(num);
        }
        return ans;
    }
};
