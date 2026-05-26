class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> s;
        int n = word.length();

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(word[i] + 32 == word[j]){
                    s.insert(word[j]);
                }
            }
        }
        return s.size();
    }
};
