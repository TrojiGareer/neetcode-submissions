class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        length = 1
        string = ""
        if s == "":
            return 0
        string += s[0]
        maxlength = 1
        for i in range(1, len(s)):
            if s[i] in string:
                pos = string.find(s[i])
                string = string[pos+1:]
            string += s[i]
            maxlength = max(maxlength, len(string))
        
        return maxlength