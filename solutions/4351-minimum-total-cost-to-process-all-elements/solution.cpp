class Solution {
public:
    long long MOD = 1e9 + 7;
    int minimumCost(vector<int>& nums, int k) {
        long long inv2 = 500000004;
        long long sum = 0;
        for(auto x : nums){
            sum += x;
        }
        if(sum <= k){return 0;}

        long long cost = 0;
        long long i = 1;
        long long resource = k;
        
        long long need = ceil( (sum - k)/(double)k);
        
        long long ans = ((need%MOD)*((need+1)%MOD))%MOD;
        ans = (ans * inv2)%MOD;
        ans = ans % MOD;
        return (int)ans;
    }
};
