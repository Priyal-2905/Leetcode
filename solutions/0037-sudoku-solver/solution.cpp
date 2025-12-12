class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int row,int col,char ch){
        for(int i = 0;i < 9;i++){
            if(board[row][i] == ch){return false;}
            if(board[i][col] == ch){return false;}
        }

        int startRow = row - row%3;
        int startCol = col - col%3;

        for(int i = startRow; i < startRow+3 ;i++){
            for(int j = startCol;j < startCol+3;j++){
                if(board[i][j] == ch){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int row = -1,col = -1;
        bool found = false;

        for(int i = 0;i < 9 && !found; i++){
            for(int j = 0;j < 9;j++){
                if(board[i][j] == '.'){
                    row = i;
                    col = j;
                    found = true;
                    break;
                }
            }
        }

        if(!found){return true;}

        for(char ch = '1'; ch <= '9' ;ch++){
            if(isSafe(board,row,col,ch)){
                board[row][col] = ch;
                if(solve(board)){
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
