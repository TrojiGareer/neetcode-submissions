class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        maxlength = 0
        count = {}
        i = 0
        for j in range(len(s)):
            count[s[j]] = 1 + count.get(s[j], 0)
            # maxf = max(maxf, count[s[i]])
            if j - i + 1 - max(count.values()) > k:
                count[s[i]] -= 1
                i += 1
            maxlength = max(maxlength, j - i + 1)
        return maxlength