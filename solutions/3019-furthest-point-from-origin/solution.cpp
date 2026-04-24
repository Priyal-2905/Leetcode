class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int r = 0;
        int l = 0;
        int space = 0;

        for(char m:moves){
            if(m == 'L')l++;
            else if(m == 'R')r++;
            else space++;
        }

        return abs(r-l)+space;
    }
};
