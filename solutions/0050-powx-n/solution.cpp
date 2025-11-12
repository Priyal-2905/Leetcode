class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long N=n;
        if(N<0){
            N =-1*N;
        }
        while(N){
            if(N%2 == 1){
                ans *= x;
                N -= 1;
            }else{
                x *= x;
                N /= 2;
            }
        }

        return n<0?(1/ans):ans;
    }
};
