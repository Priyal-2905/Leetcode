class Solution {
public:
    int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = nums.size();
        int res = INT_MAX;

        for(int i = 0;i < n;i++){
            if(m.count(nums[i])){
                res = min(res,i - m[nums[i]]);
            }

            m[reverseNum(nums[i])] = i;
        }
        return (res == INT_MAX)?-1:res;

    }
};
