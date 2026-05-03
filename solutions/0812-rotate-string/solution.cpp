class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int n1 = goal.length();

        if(n1 != n){return false;}
        for(int k = 0;k < n;k++){
            if(goal[k] != s[0]){
                continue;
            }
            bool flag = true;
            for(int i = 0;i < n;i++){
                if(s[i] != goal[(i+k)%n]){
                    flag = false;
                    break;
                }   
            }
            if(flag){return true;}
        }
        return false;
    }
};
