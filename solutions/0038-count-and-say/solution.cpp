class Solution {
public:
    string helper(string s){
        string res;
        int n = s.size();

        for(int i = 0; i < n; ){
        char c = s[i];
        int count = 0;

        while(i < n && s[i] == c){
            count++;
            i++;
        }

        res += to_string(count);
        res += c;
        }
        return res;
    }
    void solve(int n,string& res){
        if(n == 1){
            res = "1";
            return;
        }
        solve(n-1,res);
        res = helper(res);
    }
    string countAndSay(int n) {
        string res;
        solve(n,res);
        return res;
    }
};
