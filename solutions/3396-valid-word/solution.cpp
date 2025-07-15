class Solution {
public:
    bool isValid(string word) {
        int n = word.length();

        int vowels = 0 , consonant = 0;
        string vowel = "aeiouAEIOU";

        if(n < 3){return false;}

        for(auto s : word){
            if(isalpha(s)){
                if(vowel.find(s) != string::npos)
                    vowels++;
                else
                    consonant++;
            }
            else if(!isdigit(s)){
                return false;
            }
        }

        return (consonant >= 1 && vowels >= 1) ? true : false;
    }
};
