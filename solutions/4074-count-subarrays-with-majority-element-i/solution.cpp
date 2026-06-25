class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;

        for(int i = 0;i < n;i++){
            unordered_map<int,int> um;

            for(int j = i;j < n;j++){
                um[nums[j]]++;
                int len = j-i+1;
                if(2*um[target] > len){
                    count++;
                }
            }
        }
        return count;
    }
};
