class Solution {
public:
    bool inBounds(int r, int c, vector<vector<char>> &board) {
        if (r >= board.size() || r < 0 || c < 0 || c >= board[0].size()) return false;
        return true;
    }
    bool backtrack(vector<vector<char>> &board, string word, int index, int r, int c, vector<vector<int>> &visited) {
        if (!inBounds(r, c, board)) return false; 
        if (visited[r][c]) return false;
        if (index == word.size() - 1 && board[r][c] == word[index]) return true;
        visited[r][c] = 1;
        if (board[r][c] == word[index]) {
            if (backtrack(board, word, index + 1, r + 1, c, visited) ||
            backtrack(board, word, index + 1, r, c + 1, visited) ||
            backtrack(board, word, index + 1, r - 1, c, visited) ||
            backtrack(board, word, index + 1, r, c - 1, visited)) return true;
            // visited[r][c] = 0;
        }
        visited[r][c] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backtrack(board, word, 0, i, j, vis)) return true;
            }
        }
        return false;
    }
};
