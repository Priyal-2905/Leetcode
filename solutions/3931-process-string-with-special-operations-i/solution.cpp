class Solution {
public:
    string processStr(string s) {
        string res = "";
        int i = 0;

        for(char c:s){
            switch(c){
                case '#':
                    i += res.length(); 
                    res += res;
                    break;
                case '%':
                    reverse(res.begin(),res.end());
                    break;
                case '*':
                    if(res.length() > 0){
                        res.erase(i-1,1);
                        i--;
                    }
                    break;
                default :
                    i++;
                    res += c;
                    break;
            } 
        }
        return res;
    }
};
