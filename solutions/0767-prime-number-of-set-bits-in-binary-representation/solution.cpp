class Solution {
public:
    bool check(int num){
        int res = 0;
        while(num != 0){
            res += num & 1;
            num = num >> 1;
        }
        if(res <= 1){return false;}
        for(int i = 2;i*i <=res;i++){
            if(res % i == 0){
                return false;
            }
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int res = 0;
        for(int i = left;i <= right;i++){
            if(check(i)){res++;}
        }
        return res;
    }
};
