class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> suffix(n,0);
        vector<int> prefix(n,0);

        for(int i = 1;i < n;i++){
            prefix[i] = prefix[i-1];
            if(s[i-1] == 'b'){
                prefix[i]++;
            }
        }

        for(int i = n-2;i >= 0;i--){
            suffix[i] = suffix[i+1];
            if(s[i+1] == 'a'){
                suffix[i]++;
            }
        }
        int res = n;
        for(int i = 0;i < n;i++){
            res = min(res,prefix[i]+suffix[i]);
        }

        return res;

    }
};
