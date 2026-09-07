class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow, fast, slow2;
        slow = fast = slow2 = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        while (slow != slow2) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow;
    }
};
