class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        k--;
        int shift = 0;
        int op = 0;
        long long length = 1;

        while(length <= k){
            length *= 2;
            op++;
        }

        for (int i = op - 1; i >= 0; --i) {
            length /= 2;
        
            if (k >= length) {
                k -= length;
                if (operations[i] == 1) shift++;
            }
        }
        char result = 'a' + (shift % 26);
        return result;
    }
};
