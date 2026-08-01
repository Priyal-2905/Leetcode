class Solution {
public:
    int countValidPrefixes(string s) {
        int c_zero = 0;
        int c_one = 0;
        int res = 0;

        for(char c : s){
            if(c == '0'){
                c_zero++;
            }else{
                c_one++;
            }

            if(abs(c_zero - c_one) <= 1){
                res++;
            }
        }
        return res;
    }
};
