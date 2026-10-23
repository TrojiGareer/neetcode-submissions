class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        vector<int> charIdx(128, -1);
        int left = 0, right = 0;
        int longest = 1;
        for (int i = 0; i < s.size(); i++) {
            if (charIdx[s[i]] == -1) {
                charIdx[s[i]] = i;
                right = i;
            }
            else {
                if (charIdx[s[i]] >= left) {
                if (right - left + 1 > longest) {
                    longest = right - left + 1;
                }
                left = charIdx[s[i]] + 1;
            }
            charIdx[s[i]] = i;
            right = i;
            }
        }
        if (charIdx[s[right]] >= left){
            return max(longest, right - left + 1);
        }
        return longest;
    }
};
