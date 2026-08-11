class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefix = nums[0];
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                prefix += nums[i];
            } else {
                break;
            }
        }

        set<int> s;

        for(int num : nums){
            if(num >= prefix){
                s.insert(num);
            }
        }
        
        for(int i = prefix;i <= prefix+n;i++){
            if(!s.contains(i)){
                return i;
            }

        }
        
        return -1;
    }
};
