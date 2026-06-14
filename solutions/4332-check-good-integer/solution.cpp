class Solution {
public:
    bool checkGoodInteger(int n) {
        string num = to_string(n);
        int squareSum = 0, digitSum = 0;

        for(auto n : num){
            int digit = n - '0';
            digitSum += digit;
            squareSum += digit*digit;
        }

        bool ans = (squareSum - digitSum) >= 50;
        return ans;
    }
};
