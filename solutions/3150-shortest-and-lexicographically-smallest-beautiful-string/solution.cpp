class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int mini = 1e9;
        string ans = "";
        int n = s.length();

        for(int i = 0;i < n;i++){
            int ones = 0;
            string curr = "";
            for(int j = i;j < n;j++){
                if(s[j] == '1'){
                    ones++;
                }
                if(ones == k){
                    curr = curr + "1";
                    if(curr.length() < mini){
                        ans = curr;
                        mini = curr.length();
                    }

                    if(curr.length() == mini && curr < ans){
                        ans = curr;
                    }
                    break;
                }
                curr = curr + s[j];
            }

        }
        return ans;
    }
};
