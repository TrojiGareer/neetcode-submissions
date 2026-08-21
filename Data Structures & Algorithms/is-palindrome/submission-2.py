import re
class Solution:
    def isPalindrome(self, s: str) -> bool:
        string = s.lower()
        for char in " ?.!/;:',":
            string = string.replace(char, '')
        
        return string == string[::-1]