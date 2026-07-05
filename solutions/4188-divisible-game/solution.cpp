class Solution {
public:
     int MOD = 1e9 + 7;
    
    int divisibleGame(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        s.insert(2);

        for(int x:nums){
            if(x > 1){s.insert(x);}

            for(long long i = 2;i*i <= x;i++){
                if(x % i == 0){
                    s.insert(i);
                    s.insert(x/i);
                }
            }
        }

        long long bestd = LLONG_MIN;
        int bestk = INT_MAX;

        for(int k : s){
            long long curr = (nums[0]%k == 0)?nums[0] : -nums[0];
            long long best = curr;

            for(int i = 1;i < n;i++){
               long long val = (nums[i]%k == 0)?nums[i] : -nums[i];
                curr = max(val,curr+val);
                best = max(best,curr);
            }

            if(best > bestd || best == bestd && k < bestk){
                bestd = best;
                bestk = k;
            }
        }

        long long ans = ((bestd%MOD) * (bestk%MOD))%MOD;
        ans = (ans+MOD)%MOD;

        return ans;
    }
};
