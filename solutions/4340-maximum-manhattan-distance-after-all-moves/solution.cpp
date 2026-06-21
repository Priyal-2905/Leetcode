class Solution {
public:
    int maxDistance(string moves) {
        int x = 0,y = 0;
        int n = moves.length();
        sort(moves.begin(),moves.end());
        int i = 0;
        for(char move : moves){
            switch(move){
                case 'L':
                    x--;
                    break;
                case 'R':
                    x++;
                    break;
                case 'U':
                    y++;
                    break;
                    
                case 'D':
                    y--;
                    break;
            }
            if(move == '_'){break;}
            i++;
        }

        for(int j = i;i < n;i++){
            if(abs(x) > abs(y)){
                if(x > 0){x++;}
                else{x--;}
            }
            else{
                if(y > 0){y++;}
                else{y--;}
            }
        }
        
         return abs(x) + abs(y);
    }
};
