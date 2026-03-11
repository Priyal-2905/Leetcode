class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0){return 1;}
        int num = 1;
        while(num <= n)
            num = 2*num;

        num -= 1;
        return (num-n);
    }
};    
