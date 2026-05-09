class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        int c0 = 0,c1 = 0;

        for(char c:s){
            if(c == '0'){c0++;}
            else{c1++;}
        }
        int res = min(c0,(c1-1 >= 0)?c1-1:0);
        int d;

        if(n >= 2){
            int a = ((s[0] == '0')?1:0) + ((s[n-1] == '0')?1:0);
            int b = c1 - ((s[0] == '1')?1:0) - ((s[n-1] == '1')?1:0);
            d = a+b;
        }
        res = min(res,d);
        return res;
    }
};
