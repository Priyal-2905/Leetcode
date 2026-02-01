class Solution {
public:
    int countMonobit(int n) {
        int res = 1;

        int t = 2;
        for(int i = 1;i <= n;i++){
            if(i == t-1){
                res++;
                t = t*2;
            }
        }
        return res;
    }
};
