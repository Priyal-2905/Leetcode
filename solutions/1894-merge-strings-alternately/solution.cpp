class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        string res = "";
        int i = 0,j = 0;
        bool turn = true;

        while(i < m && j < n){
            if(turn){
                res += word1[i++];
                turn = false;
            }
            else{
                turn = true;
                res += word2[j++];
            }
        }

        while(i < m){
            res += word1[i++];
        }

        while(j < n){
            res += word2[j++];
        }
        return res;
    }
};
