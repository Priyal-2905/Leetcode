class Solution {
public:

    bool matching(char open , char close){
        bool match  = (open=='(' && close==')') || (open=='{' && close=='}') || (open=='[' && close==']');
        return match;
    }

    bool isValid(string s) {
        stack<char> st;
        int len = s.length();

        for(int i = 0 ; i < len ; i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    char open = st.top();
                    st.pop();
                    if(!matching(open,s[i])){
                        return false;
                    }
                }
                else{
                    return false;
                }

            }
        }

        if(!st.empty()){return false;}
        return true;

    }
};
