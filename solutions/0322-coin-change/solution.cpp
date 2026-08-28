class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& coins,int amount,int i){
        if(amount == 0){
            return 0;
        }
        if(i >= coins.size()){
            return 1e9;
        }

        if(dp[i][amount] != -1){
            return dp[i][amount];
        }

        int ans = 1e9;
        if(amount >= coins[i]){
            ans = min(ans,1 + solve(coins,amount-coins[i],i));
        }

        ans = min(ans,solve(coins,amount,i+1));

        return dp[i][amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.assign(n,vector<int>(amount+1,-1));
        int ans = solve(coins,amount,0);

        return (ans >= 1e9)?-1:ans;
    }
};
