class Solution {
public:
    int totalMoney(int n) {
        int res = 0;
        int money = 0;
        for(int i = 1;i <= n;i++){
            res += ++money;  

            if(i%7 == 0){
                money -= 6;
            }      
        }
        return res;
    }
};
