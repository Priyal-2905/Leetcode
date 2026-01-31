class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char mini = 124;
        for(auto l:letters){
            if(l > target){
                mini = min(l,mini);
            }
        }
        if(mini == 124){
            return letters[0];
        }
        return mini;
    }
};
