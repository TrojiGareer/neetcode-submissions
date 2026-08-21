class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            int line[9], col[9], box[9];
            for (int k = 0; k < 9; k++) line[k] = col[k] = box[k] = 0;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.')
                    if (line[board[i][j] - '1'] > 0) return false;
                    else line[board[i][j] - '1']++;
                if (board[j][i] != '.')
                    if (col[board[j][i] - '1'] > 0) return false;
                    else col[board[j][i] - '1']++;
                if (board[(i/3)*3 + j/3][(i%3)*3 + j%3] != '.')
                    if (box[board[(i/3)*3 + j/3][(i%3)*3 + j%3] - '1'] > 0) return false;
                    else box[board[(i/3)*3 + j/3][(i%3)*3 + j%3] - '1']++;
            }
        }
        return true;
    }
};
