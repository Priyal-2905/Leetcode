class Solution {
public:
    int passwordStrength(string password) {
        int strength = 0;
        unordered_set<char> s;

        for(char p : password){
            s.insert(p);
        }

        for(char c : s){
            if(c >= 'a' && c <= 'z'){
                strength++;
            }
            else if(c >= 'A' && c <= 'Z'){
                strength += 2;
            }
            else if(c >= '0' && c <= '9'){
                strength += 3;
            }
            else{
                strength += 5;
            }
        }
        return strength;
    }
};
