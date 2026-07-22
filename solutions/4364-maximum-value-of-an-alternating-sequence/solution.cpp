class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n == 1){return s;}

        long long a = n/2;
        long long b = a-1;

        return s + a*m - b;
    }
};
