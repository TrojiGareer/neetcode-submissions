class Solution {
public:
    void backtracking(int start, vector<int>& subset,
     vector<int>& nums, vector<vector<int>>& res) {
        res.push_back(subset);

        for (int i = start; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            backtracking(i + 1, subset, nums, res);
            // subset.erase(subset.begin() + i);
            subset.pop_back();
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        backtracking(0, subset, nums, res);
        return res;
    }
};
