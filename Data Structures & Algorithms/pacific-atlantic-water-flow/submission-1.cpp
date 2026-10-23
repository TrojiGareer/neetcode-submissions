class Solution {
public:
    bool inBounds(vector<vector<int>>&heights, int r, int c) {
        if (r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size()) return false;
        return true;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c) {
        visited[r][c] = true;

        if (inBounds(heights, r + 1, c) && heights[r + 1][c] >= heights[r][c] && visited[r + 1][c] == false) 
            dfs(heights, visited, r + 1, c);
        if (inBounds(heights, r, c + 1) && heights[r][c + 1] >= heights[r][c] && visited[r][c + 1] == false) 
            dfs(heights, visited, r, c + 1);
        if (inBounds(heights, r - 1, c) && heights[r - 1][c] >= heights[r][c] && visited[r - 1][c] == false) 
            dfs(heights, visited, r - 1, c);
        if (inBounds(heights, r, c - 1) && heights[r][c - 1] >= heights[r][c] && visited[r][c - 1] == false) 
            dfs(heights, visited, r, c - 1);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<int>> result;

        for (int i = 0; i < heights.size(); i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, heights[0].size() - 1);
        }

        for (int i = 0; i < heights[0].size(); i++) {
            dfs(heights, pacific, 0, i);
            dfs(heights, atlantic, heights.size() - 1, i);
        }

        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++) {
                if (pacific[i][j] == true && atlantic[i][j] == true) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};
