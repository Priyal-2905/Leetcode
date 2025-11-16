class Solution {
public:
    int numSub(string s) {
        int curr = 0,count = 0;
        int  mod = mod = 1e9 + 7;;

        for(char c : s){
            if(c == '1'){
                curr++;
                count = (count + curr)%mod;
            }
            else{
                curr = 0;
            }
        }

        return count;
        
    }
};
