class Solution {
public:
    int waviness(int num){
        string s = to_string(num);
        int wavy = 0;

        for(size_t i = 1;i < s.length()-1;i++){
            if ((s[i] > s[i-1] && s[i] > s[i+1] )
                || (s[i] < s[i-1] && s[i] < s[i+1]) )
            {
                wavy++;
            }
        }
        return wavy;
    }
    int totalWaviness(int num1, int num2) {
        int wavy = 0;
        for(int i = num1;i <= num2;i++){
            wavy += waviness(i);
        }
        return wavy;
    }
    
};
