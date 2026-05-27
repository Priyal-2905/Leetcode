class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int> small,cap;
        int n  = word.size();
        int res = 0;

        for(int i = 0;i < n;i++){
            char w = word[i];
            if(w >= 'A' && w <= 'Z'){
                if(!cap.contains(w)){
                    cap[w] = i;
                }
            }
        }

        for(int i = n-1;i >= 0;i--){
            char w = word[i];
            if(w >= 'a' && w <= 'z'){
                if(!small.contains(w)){
                    small[w] = i;
                }
            }
        }

        for(auto it : cap){
            char c = it.first - 'A' + 'a';

            if(small.contains(c) && it.second > small[c]){
                res++;
            }
        }

        return res;
        
    }
};
