class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int res1 = 0,res2 = 0;

        for(int i = 0;i < n;i++){
            char c1 = (i % 2)?'1':'0';
            char c2 = (i % 2)?'0':'1';

            if(s[i] != c1){res1++;}
            if(s[i] != c2){res2++;}
        }
        return (res1 < res2)?res1:res2;
    }
};
