class Solution {
public:
    string invert(string s){
        string res;
        for(char c:s){
            if(c == '1')
                res.push_back('0');
            else
                res.push_back('1');
        }
        reverse(res.begin(),res.end());
        return res;
    }
    char findKthBit(int n, int k) {
        string res = "0";

        for(int i = 2;i <= n;i++){
            res = res + "1"+invert(res);
        }

        return res[k-1];
    }
};
