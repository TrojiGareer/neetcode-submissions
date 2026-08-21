class Solution:

    def encode(self, strs: List[str]) -> str:
        encoded = ""
        for i in strs:
            encoded += str(len(i))
            encoded += "#"
            encoded += i
        print(encoded)
        return encoded
    def decode(self, s: str) -> List[str]:
        decoded = []
        j = 0
        i = 0
        while i < len(s):
            length = ""
            while i < len(s) and s[i] != '#':
                length += s[i]
                i += 1
            i += 1
            length = int(length)
            substring = s[i:i+length]
            i = i + length
            decoded.append(substring)
            j += 1
            print(length)
        return decoded
