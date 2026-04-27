class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char,int> freq,first;
        string vowels = "",t = "aeiou";
        
        for(int i = 0;i < s.length();i++){
            char c = s[i];
            if(t.find(c) != string::npos){
                if (first.find(c) == first.end()){
                    first[c] = i;
                }
                freq[c]++;
                vowels += c;
            }
        }

        sort(vowels.begin(), vowels.end(), [&](char a, char b) {
            if(freq[a] == freq[b]){return first[a] < first[b];}
            return freq[a] > freq[b];
        });
        int k = 0;
        for(char &c:s){
            if(t.find(c) != string::npos){
               c = vowels[k++];
            }
        }
        
        return s;
    }
};
