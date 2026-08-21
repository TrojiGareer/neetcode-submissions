class Solution:
    def isValid(self, s: str) -> bool:
        i = 0
        stack = []
        while i < len(s):
            if s[i] == "(" or s[i] == "[" or s[i] == "{":
                stack.append(s[i])
            else:
                if s[i] == ")":
                    if not bool(stack):
                        return False
                    popped = stack.pop()
                    if popped != "(":
                        return False
                if s[i] == "]":
                    if not bool(stack):
                        return False
                    popped = stack.pop()
                    if popped != "[":
                        return False
                if s[i] == "}":
                    if not bool(stack):
                        return False
                    popped = stack.pop()
                    if popped != "{":
                        return False
            i += 1
        if bool(stack):
            return False
        return True