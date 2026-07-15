class Solution {
public:
    int gcd(int a,int b){
        if(b == 0){
            return a;
        }
        return gcd(b,a%b);
    }
    int gcdOfOddEvenSums(int n) {
        int oddSum = 0,evenSum = 0;
        int odd = 1,even = 2;

        for(int i = 1;i <= n;i++){
            oddSum += odd;
            evenSum += even;
            odd += 2;
            even += 2;
        }
        
        return gcd(oddSum,evenSum);
    }
};
