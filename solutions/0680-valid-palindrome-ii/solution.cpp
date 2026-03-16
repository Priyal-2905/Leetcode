class Solution {
public:
    bool check(string &s, int low, int high){
        while(low < high){
            if(s[low] != s[high]) return false;
            low++;
            high--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int low = 0;
        int high = s.length()-1;
        bool flag = false;

        while(low < high){
            if(s[low] != s[high]){
                if(flag){
                    return false;
                }
                flag = true;

                return check(s, low+1, high) || check(s, low, high-1);
            }
            low++;
            high--;
        }
        return true;
    }
};
