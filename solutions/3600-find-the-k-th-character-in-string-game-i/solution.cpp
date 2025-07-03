class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        
        while(word.length() < k){
            string temp = word;
            for(int i = 0 ; i < word.length() ;i++){
                temp.push_back((word[i]+1)%123);
            }
            word = temp;
        }
        return word[k-1];
    }
};
