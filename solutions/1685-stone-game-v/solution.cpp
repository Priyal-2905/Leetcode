class Solution {
public:
    vector<int> prefix;
    vector<vector<int>> dp;

    int solve(int l,int r,vector<int>& value){
        if(l >= r){
            return 0;
        }

        if(dp[l][r] != -1){
            return dp[l][r];
        }

        int lsum = 0;
        int rsum = prefix[r+1] - prefix[l];
        int ans = 0;

        for(int i = l;i < r;i++){
            lsum += value[i];
            rsum -= value[i];

            if(lsum < rsum){
                ans = max(ans,lsum + solve(l,i,value));
            }
            else if(lsum > rsum){
                ans = max(ans,rsum + solve(i+1,r,value));
            }else{
                ans = max({
                    ans,
                    lsum + solve(l,i,value),
                    rsum + solve(i+1,r,value)
                });
            }
        }
        return dp[l][r] = ans;
    }
    int stoneGameV(vector<int>& value) {
       int n = value.size();

       prefix.resize(n+1);
       dp.assign(n,vector<int>(n,-1));

       for(int i = 0;i < n;i++){
        prefix[i+1] = prefix[i] + value[i];
       }

       return solve(0,n-1,value);
    }
};
