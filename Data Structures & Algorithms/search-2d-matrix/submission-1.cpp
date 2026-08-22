class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int st = 0, dr = (m * n) - 1;
        
        while (st <= dr) {
            int mid = st + (dr - st) / 2;
            int l = mid / n, c = mid % n;
            if (target == matrix[l][c]) return true;
            if (matrix[l][c] < target) {
                st = mid + 1;
            }
            else dr = mid - 1;
        }
        return false;
    }
};
