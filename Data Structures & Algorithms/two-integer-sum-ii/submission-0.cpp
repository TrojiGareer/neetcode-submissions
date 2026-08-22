class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int st = 0, dr = n - 1;
        int sum = numbers[st] + numbers[dr];
        while (sum != target) {
            if (sum < target) {
                st++;
            }
            else dr--;
            sum = numbers[st] + numbers[dr];
        }
        return {st + 1, dr + 1};
    }
};
