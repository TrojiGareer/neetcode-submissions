class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int st = 0, dr = n - 1;
        int max_st = height[st], max_dr = height[dr];
        int res = 0;
        while (st < dr) {
            if (max_st < max_dr) {
                res += max_st - height[st];
                st++;
                if (height[st] > max_st) max_st = height[st];
            }
            else {
                res += max_dr - height[dr];
                dr--;
                if (height[dr] > max_dr) max_dr = height[dr];
            }
        }
        return res;
    }
};
