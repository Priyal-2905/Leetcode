class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        double res = 0.0;
        int n1 = prices.size();
        int n2 = discounts.size();

        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());

        int i = n1 - 1;
        int j = n2 - 1;

        while(i >= 0 && j >= 0){
            int p = prices[i--];
            int d = discounts[j--];
            res += (p*(100-d))/100.0;
        }

        while(i >= 0){
            res += prices[i--];
        }

        return res;
        
    }
};
