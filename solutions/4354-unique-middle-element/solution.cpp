class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int,int> um;

        for(int x:nums){
            um[x]++;
        }
        int mid = nums.size()/2;

        return um[nums[mid]] == 1;
    }
};
