class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string res;
        while(b.size() < a.size()) b = "0" + b;
        while(b.size() > a.size()) a = "0" + a;
        int m = a.length()-1,n = b.length()-1;

        while(m >= 0 && n >= 0){
            int n1 = a[m] - '0';
            int n2 = b[m] - '0';
            int curr = n1 + n2 + carry;
            if(curr == 3){
                res = "1"+res;
                carry = 1;
            }
            else if(curr == 2){
                res = "0"+res;
                carry = 1;
            }
            else if(curr == 1){
                res = "1"+res;
                carry = 0;
            }
            else{
               res = "0"+res;
                carry = 0; 
            }
            m--;
            n--;
        }
        if(carry == 1){
            res = "1"+res;
        }
        return res;
    }
};
