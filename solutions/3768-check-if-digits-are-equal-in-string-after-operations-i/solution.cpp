class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.length() > 2){
            int i = 0;
            string temp;
            for(int i = 0;i < s.length()-1;i++){
                int n1 = s[i]-'0';
                int n2 = s[i+1]-'0';
                int t = (n1+n2)%10;
                
                temp.push_back(t + '0');
            }
            s = temp;
        }
        return (s[0] == s[1]);
    }
};
