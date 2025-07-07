class Solution {
public:
    int possibleStringCount(string word) {
        unordered_map<char,int> freq;

        for(int i = 1;i < word.length() ; i++){
            if(word[i] == word[i-1] )
             freq[word[i]]++;
        }
        int res = 1;
        for(auto i : freq){
                res += i.second;
        }

        return res;
        
    }
};
