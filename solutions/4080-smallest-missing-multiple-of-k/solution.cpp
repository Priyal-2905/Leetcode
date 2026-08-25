class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;

        for(int num : nums){
            s.insert(num);
        }

        for(int i = k;i <= 1000;i+=k){
            if(!s.contains(i)){
                return i;
            }
        }
        return -1;
    }
};
