class Solution {
public:
    int product(int num){
        int res = 1;
        while(num){
            res *= num%10;
            num /= 10;
        }

        return res;
    }

    int smallestNumber(int n, int t) {

        for(int i = n;i <= 100;i++){
            int a = product(i);
            if(a%t == 0){
                return i;
            }
        }

        return -1;      
    }
};
