class Solution {
public:
    string winningPlayer(int x, int y) {

        if(x < 1 || y < 4){return "Bob";}
        int turn = 0;

        while(x >= 1 && y >= 4){
            turn++;
            x--;
            y -= 4;
        }

        return (turn % 2)?"Alice":"Bob";
    }
};
