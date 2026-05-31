class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> bonus(n);

        int minPrice = INT_MAX;

        for(int i = 0;i < n;i++){
            int f1 = items[i][0];
            int gain = 0;

            for(int j = 0;j < n;j++){
                if(i == j){continue;}

                int f2 = items[j][0];

                if(f2 % f1 == 0){
                    gain++;
                }
            }
            bonus[i] = 1 + gain;
            minPrice = min(minPrice,items[i][1]);
        }

        vector<int> dp(budget+1,0);

        for(int i = 0;i < n;i++){
            int cost = items[i][1];

            for(int b = budget;b >= cost;b--){
                dp[b] = max(dp[b],dp[b-cost] + bonus[i]);
            }
        }
        int res = 0;

        for(int i = 0;i <= budget;i++){
            int remain = budget - i;

            res = max(res,dp[i] + remain/minPrice);
        }
        return res;
    }
};
