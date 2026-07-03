class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_set<char> row{};
        std::unordered_set<char> col{};
        std::unordered_set<char> box{};
       for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] != '.' && !row.count(board[i][j])){
                row.insert(board[i][j]);
            }else if(board[i][j] != '.' && row.count(board[i][j])){
                return false;
            }

            if(board[j][i] != '.' && !col.count(board[j][i])){
                col.insert(board[j][i]);
            }else if(board[j][i] != '.' && col.count(board[j][i])){
                return false;
            }
        }

        row.clear();
        col.clear();
       }

       for(int i = 0; i < 9; i+=3){
        for(int j = 0; j < 9; j+=3){
            for(int ii = i; ii < i+3; ii++){
                for(int jj = j; jj < j+3; jj++){
                    if(board[ii][jj] != '.' && !box.count(board[ii][jj])){
                        box.insert(board[ii][jj]);
                    }else if(board[ii][jj] != '.' && box.count(board[ii][jj])){
                        return false;
                    }
                }
            }
            box.clear();
        }
       }

       return true; 
    }
};
