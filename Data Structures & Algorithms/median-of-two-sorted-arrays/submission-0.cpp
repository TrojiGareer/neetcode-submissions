class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        int mid = (total + 1) / 2;
        int st = 0;
        int dr = m;
        while (st <= dr) {
            int i = (st + dr) / 2;
            int j = mid - i;
            int nums1st = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1dr = (i == m) ? INT_MAX : nums1[i];

            int nums2st = (j == 0) ? INT_MIN : nums2[j - 1];
            int nums2dr = (j == n) ? INT_MAX : nums2[j];

            if (nums1st <= nums2dr && nums2st <= nums1dr) {
                if (total % 2 == 1) {
                    return max(nums1st, nums2st);
                }
                return (max(nums1st, nums2st) + min(nums1dr, nums2dr)) / 2.0;
            }
            if (nums1st < nums2dr) {
                st = i + 1;
            }
            else {
                dr = i - 1;
            }
        }
    }
};
