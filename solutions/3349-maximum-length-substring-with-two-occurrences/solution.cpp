class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> freq;

        int start = -1;
        int ans = 0;

        for(int i = 0;i < s.length();i++){
            char c = s[i];
            freq[c]++;

            while(freq[c] > 2){
                start++;
                freq[s[start]]--;  
            }

            ans = max(ans,i-start);
        }

        return ans;
    }
};
