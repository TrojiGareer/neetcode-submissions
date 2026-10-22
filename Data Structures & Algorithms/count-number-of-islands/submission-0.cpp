class Solution {
public:
    bool inBounds (vector<vector<char>>& grid, int r, int c) {
        if (r >= grid.size() || r < 0 || c >= grid[0].size() || c < 0) return false;
        return true;
    }
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (!inBounds(grid, r, c)) return;
        if (grid[r][c] != '1') return;
        grid[r][c] = '2'; 
        dfs(grid, r + 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r - 1, c);
        dfs(grid, r, c - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int numIslands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    numIslands++;
                    dfs(grid, i, j);
                }
            }
        }
        return numIslands;
    }
};
