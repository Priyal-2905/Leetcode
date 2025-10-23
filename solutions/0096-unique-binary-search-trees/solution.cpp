class Solution {
public:
    long double factorial(int n){
        long double res = 1;
        while(n != 1){
            res *= n;
            n--;
        }
        return res;

    }

    int numTrees(int n) {
        long double num = (factorial(2*n)/(factorial(n+1)*factorial(n)));
        return (int)(num + 0.5);
    }
};
