class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string t = s + s;

        string s1 = "", s2 = "";

        for(int i = 0; i < 2*n; i++){
            if(i % 2){
                s1 += '1';
                s2 += '0';
            } else {
                s1 += '0';
                s2 += '1';
            }
        }

        int res = INT_MAX;
        int r1 = 0, r2 = 0;
        int l = 0;

        for(int i = 0;i < 2*n;i++){

            if(t[i] != s1[i]){r1++;}
            if(t[i] != s2[i]){r2++;}

            if(i-l+1 > n){
                if(t[l] != s1[l]){r1--;}
                if(t[l] != s2[l]){r2--;}
                l++;
            }

            if(i-l+1 == n){
                res = min(res,min(r1,r2));
            }
        }
        return res;
}
};
