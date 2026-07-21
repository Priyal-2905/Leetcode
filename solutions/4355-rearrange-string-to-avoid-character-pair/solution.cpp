class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string s1 = "";
        string s2 = "";
        string left = "";

        for(char c : s){
            if(c == x){
                s1 += c;
            }
            else if(c == y){
                s2 += c;
            }
            else{
                left += c;
            }
        }
        return s2+s1+left;
    }
};
