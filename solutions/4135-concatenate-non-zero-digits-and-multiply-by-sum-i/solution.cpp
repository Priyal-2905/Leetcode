class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0;
        long long sum = 0;
        int i = 0;

        while(n > 0){
            int digit = n%10;
            n /= 10;
            if(digit == 0){continue;}
            sum += digit;
            num = digit*pow(10,i) + num;
            i++;
        }

        return num*sum;
    }
};
