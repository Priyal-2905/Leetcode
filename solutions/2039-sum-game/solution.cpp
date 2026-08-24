class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int mid = n/2;

        int l = 0,r = 0;
        int cl = 0,cr = 0;
        for(int i = 0;i < mid;i++){
            if(num[i] == '?'){
                cl++;
            }else{
                l += num[i]-'0';
            }
        }

        for(int i = mid;i < n;i++){
            if(num[i] == '?'){
                cr++;
            }else{
                r += num[i]-'0';
            }
        }

        int diff = l - r;
        int t = cl - cr;

        if (t % 2 != 0)
            return true;

        return diff != -9 * t / 2;
    }
};
