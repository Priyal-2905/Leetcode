class Solution {
public:
    bool isBalanced(vector<int>& freq){
        int t = 0;

        for(int i = 0;i < 26;i++){
            if(t == 0){
                t = freq[i];
            }
            if(freq[i] != 0 && freq[i] != t){
                return false;
            }
        }
        return true;
    }
    int longestBalanced(string s) {
        int n = s.length();
        int res = 0;

        for(int i = 0; i < n; i++) {
            vector<int> freq(26, 0); 

            for(int j = i; j < n; j++) {
                freq[s[j]-'a']++;
                
                if(isBalanced(freq)){
                    res = max(res,j-i+1);
                }
            }
            
        }
        return res;
       
    }
};
