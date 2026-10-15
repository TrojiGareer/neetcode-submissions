class Solution {
public:
    void backtrack(int start, int target, vector<int>& subset, vector<int>& nums, vector<vector<int>>& res) {
        if (0 == target) {
            res.push_back(subset);
        }
        if (target < 0) return;

        for (int i = start; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            backtrack(i, target - nums[i], subset, nums, res);
            subset.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset;
        vector<vector<int>> res;
        backtrack(0, target, subset, nums, res);
        return res;
    }
};
