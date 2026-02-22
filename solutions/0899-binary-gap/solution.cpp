class Solution {
public:
    int binaryGap(int n) {
        int res = 0;
        int curr = 0;
        bool flag = false;

        while(n != 0){
            if(n & 1){
                if(flag)
                    res = max(res,curr);
                
                curr = 1;
                flag = true;  
            }
            else if(flag){
                curr++;
            }
            n = n >> 1;
        }
        return res;
    }
};
