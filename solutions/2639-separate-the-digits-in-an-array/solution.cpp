class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;

        for (int n : nums) {
            string s = to_string(n);

            for (char ch : s) {
                result.push_back(ch - '0');
            }
        }
        return result;
    }
};
