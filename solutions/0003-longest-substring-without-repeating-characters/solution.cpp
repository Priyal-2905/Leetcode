class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxi = 0,start = 0;

        unordered_map<char,int> last;

        for(int i = 0;i < n;i++){
           if(last.find(s[i]) != last.end() && last[s[i]] >= start){
                start = last[s[i]]+1;
           }

           last[s[i]] = i;

           maxi = max(maxi,i-start+1);
        }
        return maxi;
        
    }
};
