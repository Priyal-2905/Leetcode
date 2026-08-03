class Solution {
public:
   
    int solve(vector<int>& value,int i,vector<int>& dp){
        int n = value.size();

        if(i >= n){
            return 0;
        }

        if(dp[i] != INT_MIN){
            return dp[i];
        }

        int ans = INT_MIN;
        int sum = 0;
        for(int k = 0;k < 3 && i+k < n;k++){
            sum += value[i+k];
            ans = max(ans,sum - solve(value,i+k+1,dp));
        }

        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n,INT_MIN);

        int t = solve(stoneValue,0,dp);

        if(t > 0){
            return "Alice";
        }

        if(t < 0){
            return "Bob";
        }

        return "Tie";
    }
};
