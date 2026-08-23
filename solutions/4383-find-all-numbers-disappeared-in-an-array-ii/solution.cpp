class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        unordered_set<int> s;
        vector<vector<int>> ans;
        for(int num : nums){
            s.insert(num);
        }
        vector<int> missing;
        for(int i = lower;i <= upper;i++){
            if(!s.contains(i)){
                missing.push_back(i);
            }
        }
        int n = missing.size();
        if(n == 0){
            return ans;
        }
        int start = missing[0];
        
        for(int i = 1;i < n;i++){
            if(missing[i] != missing[i-1]+1){
                ans.push_back({start,missing[i-1]});
                start = missing[i];
            }
        }
        ans.push_back({start,missing.back()});
        return ans;
        
    }
};
