class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0, dr = n - 1;
        while (st <= dr) {
            int mid = st + (dr - st) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) st = mid + 1;
            else dr = mid - 1;
        }
        return -1;
    }
};
