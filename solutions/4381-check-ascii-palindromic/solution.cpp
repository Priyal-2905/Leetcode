class Solution {
public:
    string convert(int c){
        string s = "";
        while(c > 0){
            int b = c & 1;
            s = to_string(b) + s;
            c = c >> 1;
        }
        while(s.length() != 8){
            s = "0"+s;
        }
        return s;
    }
    bool isPalindromic(string s) {
        string binary = "";

        for(char c : s){
            binary += convert(c);
        }

        int low = 0;
        int high = binary.length()-1;

        while(low < high){
            if(binary[low] != binary[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
};
