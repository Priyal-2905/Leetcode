class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> res;

        for(int n : nums){
            long long curr = n;

            while(!res.empty() && res.back() == curr){
                curr += curr;
                res.pop_back();
            }
            res.push_back(curr);
        }
        return res;
    }
};
