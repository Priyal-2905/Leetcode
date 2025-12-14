class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> roman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
        };
        res = roman[s[0]];

        for(int i = 1;i < s.length();i++){
            res += roman[s[i]];
            if ((s[i-1] == 'I' && (s[i] == 'V' || s[i] == 'X')) ||
                (s[i-1] == 'X' && (s[i] == 'L' || s[i] == 'C')) ||
                (s[i-1] == 'C' && (s[i] == 'D' || s[i] == 'M')))
            {
                res -= 2 * roman[s[i-1]];
            }
        }
        return res;
    }
};
