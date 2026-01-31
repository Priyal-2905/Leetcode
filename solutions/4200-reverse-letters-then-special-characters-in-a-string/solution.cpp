class Solution {
public:
    string reverseByType(string s) {
        stack<char> st1;
        stack<char> st2;
        int n = s.length();
        
        for(int i = 0;i < n;i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                st1.push(s[i]);
            }
            else{
                st2.push(s[i]);
            }
        }
        for(int i = 0;i < n;i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                s[i] = st1.top();
                st1.pop();
            }
            else{
                s[i] = st2.top();
                st2.pop();
            }
        }
        return s;
        
    }
};
