import re
class Solution:
    def isPalindrome(self, s: str) -> bool:
        string = s.lower()
        for char in " ?.!/;:',":
            string = string.replace(char, '')
        rev = ''.join(reversed(string))
        return string == rev