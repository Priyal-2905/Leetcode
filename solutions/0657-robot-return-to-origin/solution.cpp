class Solution {
public:
    bool judgeCircle(string moves) {
        int i = 0;
        int j = 0;

        for(char move:moves){
            if(move == 'U'){
                j+=1;
            }
            else if(move == 'D'){
                j -= 1;
            }
            else if(move == 'L'){
                i -= 1;
            }
            else{
                i += 1;
            }
        }
        return (i == 0 && j == 0);
    }
};
