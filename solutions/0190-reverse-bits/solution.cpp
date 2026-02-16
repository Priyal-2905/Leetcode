class Solution {
public:
    int reverseBits(int n) {
        vector<int> bits(32,0);
        int i = 0;
        while(n != 0){
            int t = n %2;
            bits[i] = t;
            n = n >> 1;
            i++;
        }
        int res = bits[31];
        for(int i=0;i<31;i++){
            res = res + bits[i]*pow(2,31-i);
        }
        return res;
    }
};
