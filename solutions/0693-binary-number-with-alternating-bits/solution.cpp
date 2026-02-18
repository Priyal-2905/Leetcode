class Solution {
public:
    bool hasAlternatingBits(int n) {
        int num = n,last = -1;
        while(num != 0){
            int bit = num & 1;
            num = num >> 1;
            
            if(bit != -1 && last == bit){
                return false;
            }
            last = bit;
        }
        return true;
    }
};
